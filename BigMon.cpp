#include "stdafx.h"
#include "BigMon.h"
#include "MonBullet.h"
#include "ObjMgr.h"
CBigMon::CBigMon()
{
}


CBigMon::~CBigMon()
{
	Release();
}

HRESULT CBigMon::Initialize()
{
	m_tInfo.vSize = D3DXVECTOR3(75.f, 80.f, 0.f);
	m_tObjInfo.ihp = 30;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 5.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_dwDelayTime = 1000;
	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	return S_OK;
}

void CBigMon::Ready()
{
}

int CBigMon::Update()
{
	if (m_bDead) {
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMSfx>::Create(m_tInfo.vPos), OBJID::SFX);
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


	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}


	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		for (int i = -1; i <= 1; i++) {
			D3DXVECTOR3 temp = { m_tInfo.vPos.x - 35 * i,m_tInfo.vPos.y - abs(35 * i),0.f };
			CObj* pObj = CAbstractFactory<CMonBullet>::Create(temp);
			static_cast<CMonBullet*>(pObj)->Ready();
			CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::MONSTERBULLET);
		}
		m_dwTime = GetTickCount();
	}

	if ((abs(m_tInfo.vPos.x - m_dist.x) < 30) && abs(m_tInfo.vPos.y - m_dist.y) < 30) {
		m_bMove = true;
	}
	if(m_bMove)
		Moving();
	if (!m_bMove) {
		m_tInfo.vDir = m_dist - m_tInfo.vPos;
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
		m_tInfo.vPos += m_tInfo.vDir * 5.f;
	}



	return OBJ_NOEVENT;
}

void CBigMon::Late_Update()
{
	if (m_tInfo.vPos.y < -120 || m_tInfo.vPos.y > WINCY)
		m_bDead = OBJ_DEAD;
	if (m_tObjInfo.ihp <= 0)
		m_bDead = OBJ_DEAD;
}

void CBigMon::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 4; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);
}

void CBigMon::Release()
{
}

void CBigMon::Moving()
{
	m_tInfo.vDir = { cosf(m_MoveAngle) , sinf(m_MoveAngle), 0.f };
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	m_tInfo.vPos += m_tInfo.vDir;
	m_MoveAngle += 0.1f;
}
