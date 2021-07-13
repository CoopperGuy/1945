#include "stdafx.h"
#include "MonExp.h"


CMonExp::CMonExp()
{
}


CMonExp::~CMonExp()
{
	Release();
}

HRESULT CMonExp::Initialize()
{
	m_tInfo.vSize = D3DXVECTOR3(10.f, 10.f, 0.f);
	m_dwTime = GetTickCount();
	m_tObjInfo.fspd = 1.5f;
	m_dwDelayTime = 400;

	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	return S_OK;
}

void CMonExp::Ready()
{

}

int CMonExp::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	D3DXMATRIX matScale, matRotZ, matTrans, matWorld;

	D3DXMatrixScaling(&matScale, 0.7f, 0.7f, 0.7f);
	D3DXVECTOR3 Look = { 1.f,0.f,0.f };
	float fDot;
	fDot = D3DXVec3Dot(&m_tInfo.vDir, &Look);
	m_fRad = acosf(fDot);
	if (m_dist.y - m_tInfo.vPos.y > 0)
		m_fRad = -m_fRad;


	D3DXMatrixRotationZ(&matRotZ, (m_fRad));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	matWorld = matScale * matRotZ *matTrans;



	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	m_tInfo.vPos += m_tInfo.vDir*m_tObjInfo.fspd;

	return OBJ_NOEVENT;
}

void CMonExp::Late_Update()
{
	if (m_dwTime + m_dwDelayTime < GetTickCount())
		m_bDead = OBJ_DEAD;

}

void CMonExp::Render(HDC _DC)
{
	MoveToEx(_DC, m_vQ[0].x, m_vQ[0].y, nullptr);

	LineTo(_DC, (m_vQ[1].x + m_vQ[2].x)*0.5, (m_vQ[1].y + m_vQ[2].y)*0.5);
	LineTo(_DC, m_vQ[3].x, m_vQ[3].y);
	LineTo(_DC, m_vQ[0].x, m_vQ[0].y);
}

void CMonExp::Release()
{
}
