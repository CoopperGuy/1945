#include "stdafx.h"
#include "FinalBoss.h"
#include "BossBullet.h"
#include "ObjMgr.h"
#include "ExplodeBullet.h"

CFinalBoss::CFinalBoss()
	:m_ePattern(END), m_bPatternEnd(false)
{
}


CFinalBoss::~CFinalBoss()
{
}

HRESULT CFinalBoss::Initialize()
{
	
	m_tInfo.vSize = D3DXVECTOR3(400.f, 200.f, 0.f);
	m_tObjInfo.ihp = 1000;
	m_tObjInfo.iatk = 2;
	m_tObjInfo.fspd = 50.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_dwDelayTime = 500;
	
	m_PatternTime = GetTickCount();
	m_PatternDelay = 2400;

	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };

	return S_OK;
}

void CFinalBoss::Ready()
{
}

int CFinalBoss::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);
	matWorld = matScale * matTrans;

	for (int i = 0; i < 4; ++i)
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);


	//pattern
	if (m_PatternTime + m_PatternDelay < GetTickCount()) {
		//m_ePattern = ATTACK1;
		m_ePattern = PATTERN2(rand() % END);
		m_fAngle = 0.f;
		m_PatternTime = GetTickCount();
	}

	//
	switch (m_ePattern)
	{
	case ATTACK1:
		Attack1();
		m_dwDelayTime = 200;
		break;
	case ATTACK2:
		Attack2();
		m_dwDelayTime = 1000;
		break;
	case ATTACK3:
		Attack3();
		m_dwDelayTime = 2500;
		break;
	/*case ATTACK_MOVEMENT:
		Attack_Movement();
		m_dwDelayTime = 500;
		break;*/
	}


	return OBJ_NOEVENT;
}

void CFinalBoss::Late_Update()
{
	if (m_tObjInfo.ihp <= 0)
		m_bDead = OBJ_DEAD;
}

void CFinalBoss::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 4; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);
}

void CFinalBoss::Release()
{
}

void CFinalBoss::Attack1()
{
	//0.5sec
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		for (int i = 0; i < 30; ++i) {
			m_fAngle += 100.f;
			D3DXVECTOR3 dir;
			if(i % 2 == 0)
				dir = { cosf(D3DXToRadian(m_fAngle + i)), sinf(D3DXToRadian(m_fAngle - i)) , 0.f };
			else
				dir = { cosf(D3DXToRadian(m_fAngle - i)), sinf(D3DXToRadian(m_fAngle + i)) , 0.f };
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBossBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		}
		m_dwTime = GetTickCount();
	}
}

void CFinalBoss::Attack2()
{
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		D3DXVECTOR3 dir = {0.f, 1.f , 0.f };
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CExplodeBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		m_dwTime = GetTickCount();
	}
}

void CFinalBoss::Attack3()
{
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		float fTemp = m_tInfo.vPos.x;
		D3DXVECTOR3 dir = { 0.f, 1.f , 0.f };
		m_tInfo.vPos.x -= 200.f;
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CExplodeBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		m_tInfo.vPos.x += 200.f;
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CExplodeBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		m_tInfo.vPos.x += 200.f;
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CExplodeBullet>::Create(m_tInfo.vPos, dir), OBJID::MONSTERBULLET);
		m_tInfo.vPos.x = fTemp;
		m_dwTime = GetTickCount();
	}
}

void CFinalBoss::Attack_Movement()
{
}
