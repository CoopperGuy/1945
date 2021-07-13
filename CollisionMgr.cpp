#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "Player.h"
CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::Collision_Check_Matrix(CObj * _Dst, CObj * _Src)
{

	D3DXVECTOR3 vecLength = { abs(_Dst->Get_Pos().x - _Src->Get_Pos().x),abs(_Dst->Get_Pos().y - _Src->Get_Pos().y), abs(_Dst->Get_Pos().z - _Src->Get_Pos().z) };
	D3DXVECTOR3 vecSize = { (_Dst->Get_Size().x + _Src->Get_Size().x) * 0.3f ,(_Dst->Get_Size().y + _Src->Get_Size().y) * 0.3f, (_Dst->Get_Size().z + _Src->Get_Size().z) * 0.3f };
	float flength =D3DXVec3Length(&vecLength);
	float fdist = D3DXVec3Length(&vecSize);
	if (flength < fdist) {
		_Dst->Set_Hp(-_Src->Get_Dmg());
		_Src->Set_Dead();
		return true;
	}
	return false;
}
bool CCollisionMgr::Collision_Check_Matrix_Item(CObj * _Dst, CObj * _Src)
{
	D3DXVECTOR3 vecLength = { abs(_Dst->Get_Pos().x - _Src->Get_Pos().x),abs(_Dst->Get_Pos().y - _Src->Get_Pos().y), abs(_Dst->Get_Pos().z - _Src->Get_Pos().z) };
	D3DXVECTOR3 vecSize = { (_Dst->Get_Size().x + _Src->Get_Size().x) * 0.5f ,(_Dst->Get_Size().y + _Src->Get_Size().y) * 0.5f, (_Dst->Get_Size().z + _Src->Get_Size().z) * 0.5f };
	float flength = D3DXVec3Length(&vecLength);
	float fdist = D3DXVec3Length(&vecSize);
	if (flength < fdist) {
		static_cast<CPlayer*>(_Dst)->Set_Power();
		_Src->Set_Dead();
		return true;
	}
	return false;
}
