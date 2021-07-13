#include "stdafx.h"
#include "ExplodeBullet.h"
#include "ObjMgr.h"
#include "BossBullet.h"

CExplodeBullet::CExplodeBullet()
	:m_fAngle(0.f)
{
}


CExplodeBullet::~CExplodeBullet()
{
	Release();
}

HRESULT CExplodeBullet::Initialize()
{
	m_tInfo.vDir = D3DXVECTOR3(0.f, 1.f, 0.f);
	m_tInfo.vSize = D3DXVECTOR3(30.f, 30.f, 0.f);
	m_tObjInfo.ihp = 1;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 3.f;
	m_tObjInfo.fagl = 0.f;

	dwExplodeTime = GetTickCount();
	dwExplodeDelayTime = 2500;

	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };



	return S_OK;
}

void CExplodeBullet::Ready()
{
	if (!CObjMgr::Get_Instance()->Player_Empty()) {
		m_tInfo.vDir = CObjMgr::Get_Instance()->Get_Player()->Get_Pos() - m_tInfo.vPos;
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	}
}

int CExplodeBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	matWorld = matScale * matTrans;


	for (int i = 0; i < 4; ++i)
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);

	m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;


	if (dwExplodeTime + dwExplodeDelayTime < GetTickCount()) {
		for (int i = 0; i < 30; ++i) {
			m_fAngle += 100.f;

			D3DXVECTOR3 dir = { cosf(D3DXToRadian(m_fAngle)), sinf(D3DXToRadian(m_fAngle)) , 0.f };
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBossBullet>::Create(m_tInfo.vPos + dir * 75.f, dir), OBJID::MONSTERBULLET);
		}
		m_bDead = true;
	}


	return OBJ_NOEVENT;
}

void CExplodeBullet::Late_Update()
{
	if (m_tInfo.vPos.x < 0.f || m_tInfo.vPos.x > WINCX ||
		m_tInfo.vPos.y <0.f || m_tInfo.vPos.y > WINCY)
		m_bDead = true;
}

void CExplodeBullet::Render(HDC _DC)
{
	RECT rc = {};
	rc.left = m_vQ[0].x;
	rc.top = m_vQ[0].y;
	rc.right = m_vQ[2].x;
	rc.bottom = m_vQ[2].y;

	Ellipse(_DC, rc.left, rc.top, rc.right, rc.bottom);
}

void CExplodeBullet::Release()
{
}
