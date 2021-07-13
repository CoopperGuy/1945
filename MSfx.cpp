#include "stdafx.h"
#include "MSfx.h"
#include "ObjMgr.h"
#include "MonExp.h"

CMSfx::CMSfx()
{
}


CMSfx::~CMSfx()
{
}

HRESULT CMSfx::Initialize()
{
	for (int i = 0; i < 12; i++) {
		D3DXVECTOR3 dir = { cosf(D3DXToRadian(m_fAngle)),sinf(D3DXToRadian(m_fAngle)),0.f };
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMonExp>::Create(m_tInfo.vPos, dir, m_tInfo.vPos), OBJID::SFX);
		m_fAngle += 30.f;
	}
	return S_OK;
}

int CMSfx::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	return OBJ_NOEVENT;
}

void CMSfx::Late_Update()
{
	m_bDead = OBJ_DEAD;

}

void CMSfx::Render(HDC _DC)
{
}

void CMSfx::Release()
{
}
