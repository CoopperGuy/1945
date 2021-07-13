#include "stdafx.h"
#include "Boss.h"
#include "ObjMgr.h"
#include "BossBullet.h"
#include "BGuideBullet.h"
#include "FinalBoss.h"
#include "Time.h"
CBoss::CBoss()
{
}


CBoss::~CBoss()
{
}

HRESULT CBoss::Initialize()
{
	m_tInfo.vSize = D3DXVECTOR3(250.f, 125.f, 0.f);
	m_tObjInfo.ihp = 300;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 5.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_dwDelayTime = 400;
	m_PatternTime = GetTickCount();
	m_PateernDelay = 2400;
	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	srand(unsigned(time(NULL)));
	return S_OK;
}

void CBoss::Ready()
{
}

int CBoss::Update()
{
	if (m_bDead) {
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CFinalBoss>::Create({WINCX>>1,WINCY>>1,0.f}), OBJID::MONSTER);
		return OBJ_DEAD;
	}
	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);
	// 	matWorld = 스 * 자 * 이 * 공 * 부;
	// 				케일  전   동   전   모
	matWorld = matScale * matTrans;
	//D3DXVec3TransformCoord(); // x,y,z w = 1
	//D3DXVec3TransformNormal(); // x,y,z w = 0


	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}

	if (m_PatternTime + m_PateernDelay < GetTickCount()) {
		m_ePattern = CBoss::PATTERN(rand() % CBoss::PATTERN::P_END);
		m_fAngle = 0.f;
		m_PatternTime = GetTickCount();
	}

	switch (m_ePattern)
	{
	case CBoss::P_ATTACK:
		Attack_First();
		m_dwDelayTime = 400;
		break;
	case CBoss::P_ATTACK2_:
		Attack_Second();
		m_dwDelayTime = 400;
		break;
	case CBoss::P_MOVE:
		BossMove();
		m_dwDelayTime = 700;
		break;
	case CBoss::P_MOVEATK:
		BossMoveAttack();
		m_dwDelayTime = 300;
		break;
	}


	return OBJ_NOEVENT;
}

void CBoss::Late_Update()
{
	if (m_tInfo.vPos.x < 120)
		m_tInfo.vPos.x = 120.f;
	if (m_tInfo.vPos.x > WINCX - 120)
		m_tInfo.vPos.x = WINCX - 120;

	if (m_tInfo.vPos.y < 75)
		m_tInfo.vPos.y = 75;
	if (m_tInfo.vPos.y > 300)
		m_tInfo.vPos.y = 300;
	if (m_tObjInfo.ihp <= 0)
		m_bDead = OBJ_DEAD;
}

void CBoss::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 4; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);
}

void CBoss::Release()
{
}

void CBoss::Attack_First()
{
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		for (int i = 0; i < 30; i++) {
			m_fAngle += 12.f;
			D3DXVECTOR3 dir = { cosf(D3DXToRadian(m_fAngle)),sinf(D3DXToRadian(m_fAngle)),0.f };
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBossBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		}
		m_dwTime = GetTickCount();
	}
	m_fAngle += 10.f;

}

void CBoss::Attack_Second()
{
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {

		for (int i = -2; i < 2; i++) {
			D3DXVECTOR3 temp = m_tInfo.vPos + D3DXVECTOR3({50.f * i, 0.f, 0.f});
			CObj* pObj = CAbstractFactory<CBGuideBullet>::Create(temp);
			static_cast<CBGuideBullet*>(pObj)->Ready();
			CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::MONSTERBULLET);
		}
		m_dwTime = GetTickCount();
	}

}

void CBoss::BossMove()
{
	m_tInfo.vDir = { cosf(m_MoveAngle)  , sinf(m_MoveAngle) * 0.5f, 0.f };
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	m_tInfo.vPos += m_tInfo.vDir * 5.f;	
	m_MoveAngle += 0.05f;

	if (m_dwTime + m_dwDelayTime  < GetTickCount()) {
		for (int i = 0; i < 20; i++) {
			m_fAngle += 24.f;
			D3DXVECTOR3 dir = { cosf(D3DXToRadian(m_fAngle)),sinf(D3DXToRadian(m_fAngle)),0.f };
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBossBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		}
		m_dwTime = GetTickCount();
	}
}

void CBoss::BossMoveAttack()
{
	m_tInfo.vDir = { cosf(m_MoveAngle) , 0.f, 0.f };
//	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	m_tInfo.vPos += m_tInfo.vDir * 5.f;
	m_MoveAngle += 0.1f;

	if (m_dwTime + m_dwDelayTime  < GetTickCount()) {
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBossBullet>::Create(m_tInfo.vPos, { 0.f,1.f,0.f }), OBJID::MONSTERBULLET);
		m_dwTime = GetTickCount();
	}
}
