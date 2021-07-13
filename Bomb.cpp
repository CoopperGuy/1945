#include "stdafx.h"
#include "Bomb.h"
#include "ObjMgr.h"
#include "Bullet.h"
#include "ObjMgr.h"
CBomb::CBomb()
{
}


CBomb::~CBomb()
{
}

HRESULT CBomb::Initialize()
{
	m_tInfo.vDir = D3DXVECTOR3(0.f, -1.f, 0.f);
	m_tInfo.vSize = D3DXVECTOR3(50.f, 50.f, 0.f);
	m_tObjInfo.ihp = 999999;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 5.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_time = GetTickCount();
	m_dwDelayTime = 200;
	m_delay = 8000;

	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };

	m_pPos = CObjMgr::Get_Instance()->Get_Player()->Get_Pos();
	return S_OK;

}

int CBomb::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(00.f));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);
	// 	matWorld = 스 * 자 * 이 * 공 * 부;
	// 				케일  전   동   전   모
	matWorld = matScale * matRotZ * matTrans;
	//D3DXVec3TransformCoord(); // x,y,z w = 1
	//D3DXVec3TransformNormal(); // x,y,z w = 0

	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	if (m_pPos.y > m_tInfo.vPos.y) {
		m_tObjInfo.fspd = 0.5f;
	}
	if (m_time + m_delay < GetTickCount()) {
		m_tObjInfo.fspd = 10.f;
		m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;
		return OBJ_NOEVENT;
	}		
	m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;


	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create(m_tInfo.vPos), OBJID::PLAYERBULLET);
		m_dwTime = GetTickCount();
	}

	return OBJ_NOEVENT;
}

void CBomb::Late_Update()
{
	if (m_tInfo.vPos.y < -50)
		m_bDead = OBJ_DEAD;
}

void CBomb::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 4; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);
}

void CBomb::Release()
{
}
