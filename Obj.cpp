#include "stdafx.h"
#include "Obj.h"


CObj::CObj() :m_bDead(OBJ_NOEVENT)
{
	ZeroMemory(m_vP, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(m_vQ, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(&m_tInfo, sizeof(INFO));
}


CObj::~CObj()
{
}
