#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}


CItem::~CItem()
{
}

HRESULT CItem::Initialize()
{
	m_tInfo.vSize = D3DXVECTOR3(10.f, 10.f, 0.f);
	m_tObjInfo.ihp = 0;
	m_tObjInfo.iatk = 0;
	m_tObjInfo.fspd = 3.f;
	m_tObjInfo.fagl = 0.f;

	m_dwTime = GetTickCount();
	m_dwDelayTime = 400;
	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	return S_OK;
}

int CItem::Update()
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
	m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;
	return OBJ_NOEVENT;
}

void CItem::Late_Update()
{
	if (m_tInfo.vPos.x <0.f || m_tInfo.vPos.x >WINCX) {
		m_tInfo.vDir.x = -m_tInfo.vDir.x;
		m_tInfo.vPos += m_tInfo.vDir;
		bound--;
	}
	if (m_tInfo.vPos.y <0.f || m_tInfo.vPos.y >WINCY) {
		m_tInfo.vDir.y = -m_tInfo.vDir.y;
		m_tInfo.vPos += m_tInfo.vDir;
		bound--;
	}
	if (bound < 0)
		m_bDead = OBJ_DEAD;
}

void CItem::Render(HDC _DC)
{

	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	for (int i = 1; i < 3; ++i)
		LineTo(_DC, m_vQ[i].x, m_vQ[i].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);
}

void CItem::Release()
{
}
