#include "stdafx.h"
#include "Obj.h"


CObj::CObj() :m_bDead(OBJ_NOEVENT), m_tObjInfo(1, 0, 5.f, 0.f)

{
	ZeroMemory(m_vP, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(m_vQ, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(&m_tInfo, sizeof(INFO));
}


CObj::~CObj()
{
}
