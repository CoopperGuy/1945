#include "stdafx.h"
#include "NMonster.h"
#include "ObjMgr.h"
#include "MonBullet.h"
#include "Item.h"
CNMonster::CNMonster()
{
}


CNMonster::~CNMonster()
{
}

HRESULT CNMonster::Initialize()
{
	m_tInfo.vSize = D3DXVECTOR3(30.f, 30.f, 0.f);
	m_tObjInfo.ihp = 1;
	m_tObjInfo.iatk = 1;
	m_tObjInfo.fspd = 5.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_dwDelayTime = 1200;
	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	return S_OK;
}

void CNMonster::Ready()
{
}

int CNMonster::Update()
{
	if (m_bDead) {
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMSfx>::Create(m_tInfo.vPos), OBJID::SFX);
		int rad = rand() % 10;
		if(rad == 5)
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CItem>::Create({ 300.f,250.f,0.f }, { -1.f,1.f,0.f }, 300, 5), OBJID::ITEM);
		return OBJ_DEAD;
	}
	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	/////
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

	D3DXVECTOR3 vLook{ 1.f, 0.f, 0.f };
	 
	float fCosTheta = m_tInfo.vDir.x * vLook.x + m_tInfo.vDir.y * vLook.y + m_tInfo.vDir.z * vLook.z; 
	float fAngle = acosf(fCosTheta); 
	////
	D3DXMatrixRotationZ(&matRotZ, fAngle);
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
		CObj* pObj = CAbstractFactory<CMonBullet>::Create(m_tInfo.vPos);
		static_cast<CMonBullet*>(pObj)->Ready();
		CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::MONSTERBULLET);
		m_dwTime = GetTickCount();
	}
	m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;
	return OBJ_NOEVENT;
}

void CNMonster::Late_Update()
{
	if (m_tInfo.vPos.y < -120 || m_tInfo.vPos.y > WINCY)
		m_bDead = OBJ_DEAD;
	if (m_tObjInfo.ihp <= 0)
		m_bDead = OBJ_DEAD;
}

void CNMonster::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 4; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);

}

void CNMonster::Release()
{
}
