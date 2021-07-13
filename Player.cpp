#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "Bullet.h"
#include "Bomb.h"
#include "Sfx.h"

int CPlayer::Life = 99;

CPlayer::CPlayer() 
{


}


CPlayer::~CPlayer()
{
	Release();
}

HRESULT CPlayer::Initialize()
{

	m_tInfo.vPos = { 300.f, 900.f, 0.f };
	m_tInfo.vDir = D3DXVECTOR3(1.f, 1.f, 0.f);
	m_tInfo.vSize = D3DXVECTOR3(30.f, 30.f, 0.f);
	m_tObjInfo.ihp = 9999;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 5.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_dwDelayTime = 100;
	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	return S_OK;
}

int CPlayer::Update()
{
	if (m_bDead) {
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CSfx>::Create(m_tInfo.vPos), OBJID::SFX);
		if (Life > 0) {
			CObjMgr::Get_Instance()->Add_Object(CPlayer::Create(), OBJID::PLAYER);
			Life--;
		}
		return OBJ_DEAD;
	}
	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(00.f));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);
	// 	matWorld = 스 * 자 * 이 * 공 * 부;
	// 				케일  전   동   전   모
	matWorld = matScale * matRotZ * matTrans;
	//D3DXVec3TransformCoord(); // x,y,z w = 1
	//D3DXVec3TransformNormal(); // x,y,z w = 0

	//행렬을 이용한 객체 상태 표현. ! ////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}

	if (!m_bMove) {
		m_tInfo.vDir = m_dist - m_tInfo.vPos;
		float size = D3DXVec3Length(&m_tInfo.vDir);
		if (size < 10.f) {
			m_bMove = true;
			m_ltime = GetTickCount();
		}
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
		m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd*2;
		return OBJ_NOEVENT;
	}
	if (m_ltime + m_delay < GetTickCount())
		m_tObjInfo.ihp = 1;

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT)) {
		m_tInfo.vPos.x -= m_tObjInfo.fspd;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT)) {
		m_tInfo.vPos.x += m_tObjInfo.fspd;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP)) {
		m_tInfo.vPos.y -= m_tObjInfo.fspd;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN)) {
		m_tInfo.vPos.y += m_tObjInfo.fspd;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('A')) {
		if (m_dwTime + m_dwDelayTime < GetTickCount()) {
			switch (Power)
			{
			case 0:
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create(m_tInfo.vPos), OBJID::PLAYERBULLET);
				break;
			case 1:
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create({ m_tInfo.vPos.x - 10,m_tInfo.vPos.y,0.f }), OBJID::PLAYERBULLET);
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create({ m_tInfo.vPos.x + 10,m_tInfo.vPos.y,0.f }), OBJID::PLAYERBULLET);
				break;
			case 2:
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create({ m_tInfo.vPos.x - 10,m_tInfo.vPos.y,0.f }), OBJID::PLAYERBULLET);
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create(m_tInfo.vPos), OBJID::PLAYERBULLET);
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create({ m_tInfo.vPos.x + 10,m_tInfo.vPos.y,0.f }), OBJID::PLAYERBULLET);
				break;
			case 3:
				for (int i = -2; i < 2; i++) {
					CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create({ m_tInfo.vPos.x + (10 * i),m_tInfo.vPos.y,0.f }), OBJID::PLAYERBULLET);
				}
				break;
			}
			m_dwTime = GetTickCount();
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Down('S')) {
		if (Bomb > 0) {
			for (int i = -2; i <= 2; i++) {
				CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBomb>::Create({ m_tInfo.vPos.x + (i*50) ,float(WINCY + (25*abs(i))) ,0.f }), OBJID::PLAYERBOMB);
			}
			Bomb--;
		}
	}
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	if (m_tInfo.vPos.x < 15)
		m_tInfo.vPos.x = 15.f;
	if (m_tInfo.vPos.x > WINCX-15)
		m_tInfo.vPos.x = WINCX-15;

	if (m_tInfo.vPos.y < 15)
		m_tInfo.vPos.y = 15;
	if (m_tInfo.vPos.y > WINCY-15)
		m_tInfo.vPos.y = WINCY-15;

	if (m_tObjInfo.ihp <= 0)
		m_bDead = OBJ_DEAD;
}

void CPlayer::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 4; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);

}

void CPlayer::Release()
{
}

CObj * CPlayer::Create()
{
	CPlayer* pInstance = new CPlayer;
	if (FAILED(pInstance->Initialize()))
	{
		Safe_Delete(pInstance);
		return nullptr;
	}
	return pInstance;
}
