#include "stdafx.h"
#include "BossBullet.h"
#include "ObjMgr.h"

CBossBullet::CBossBullet()
{
}


CBossBullet::~CBossBullet()
{
	Release();
}

HRESULT CBossBullet::Initialize()
{
	m_tInfo.vSize = D3DXVECTOR3(30.f, 30.f, 0.f);
	m_tObjInfo.ihp = 1;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 3.f;
	m_tObjInfo.fagl = 0.f;

	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };



	return S_OK;
}

void CBossBullet::Ready()
{
	if (!CObjMgr::Get_Instance()->Player_Empty()) {
		m_tInfo.vDir = CObjMgr::Get_Instance()->Get_Player()->Get_Pos() - m_tInfo.vPos;
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	}
}

int CBossBullet::Update()
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

	m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;


	return OBJ_NOEVENT;
}

void CBossBullet::Late_Update()
{
	if (m_tInfo.vPos.x < 0.f || m_tInfo.vPos.x > WINCX ||
		m_tInfo.vPos.y <0.f || m_tInfo.vPos.y > WINCY)
		m_bDead = true;
}

void CBossBullet::Render(HDC _DC)
{
	RECT rc = {};
	rc.left = m_vQ[0].x;
	rc.top = m_vQ[0].y;
	rc.right = m_vQ[2].x;
	rc.bottom = m_vQ[2].y;

	Ellipse(_DC, rc.left, rc.top, rc.right, rc.bottom);
}

void CBossBullet::Release()
{
}
