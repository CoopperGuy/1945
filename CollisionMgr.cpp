#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::Collision_Check_Matrix(CObj * _Dst, CObj * _Src)
{
	float CenterX = abs(_Dst->Get_Pos().x - _Src->Get_Pos().x);
	float CenterY = abs(_Dst->Get_Pos().y - _Src->Get_Pos().y);

	float rX = (_Dst->Get_Size().x + _Src->Get_Size().x) * 0.5;
	float rY = (_Dst->Get_Size().y + _Src->Get_Size().y) * 0.5;

	if (CenterX < rX && CenterY < rY) {
		return true;
	}
	return false;
}
