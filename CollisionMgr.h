#pragma once

#ifndef __COLLISIONMGR_H__
#define __COLLISIONMGR_H__

class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static bool Collision_Check_Matrix(CObj* _Dst, CObj* _Src);
	static bool CCollisionMgr::Collision_Check_Matrix_Item(CObj * _Dst, CObj * _Src);

};


#endif // !__COLLISIONMGR_H__
