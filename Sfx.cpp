#include "stdafx.h"
#include "Sfx.h"
#include "ObjMgr.h"
#include "Explosion.h"

CSfx::CSfx()
{
}


CSfx::~CSfx()
{
}

HRESULT CSfx::Initialize()
{
	for (int i = 0; i < 12; i++) {
		D3DXVECTOR3 dir = { cosf(D3DXToRadian(m_fAngle)),sinf(D3DXToRadian(m_fAngle)),0.f };
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CExplosion>::Create(m_tInfo.vPos, dir,m_tInfo.vPos), OBJID::SFX);
		m_fAngle += 30.f;
	}
	return S_OK;
}

int CSfx::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	return OBJ_NOEVENT;
}

void CSfx::Late_Update()
{
	m_bDead = OBJ_DEAD;
}

void CSfx::Render(HDC _DC)
{
}

void CSfx::Release()
{
}
