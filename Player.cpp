#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"

CPlayer::CPlayer() 

{


}


CPlayer::~CPlayer()
{
	Release();
}

HRESULT CPlayer::Initialize()
{

	m_tInfo.vPos = { 100.f, 0.f, 0.f };
	m_tInfo.vDir = D3DXVECTOR3(1.f, 1.f, 0.f);
	m_tInfo.vSize = D3DXVECTOR3(100.f, 100.f, 0.f);

	m_vP[0] = { -m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { m_tInfo.vSize.x * 0.5f, -m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -m_tInfo.vSize.x * 0.5f, m_tInfo.vSize.y * 0.5f, 0.f };
	return S_OK;
}

int CPlayer::Update()
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

	//행렬을 이용한 객체 상태 표현. ! ////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}


	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT)) {
		m_tInfo.vPos.x -= m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT)) {
		m_tInfo.vPos.x += m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP)) {
		m_tInfo.vPos.y -= m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN)) {
		m_tInfo.vPos.y += m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE)) {

	}
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
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
