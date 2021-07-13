#pragma once

#ifndef __CBIGMON_H__
#define __CBIGMON_H__


#include "Monster.h"
class CBigMon :
	public CMonster
{
public:
	CBigMon();
	virtual ~CBigMon();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	void Set_Dist(D3DXVECTOR3 _dist) { m_dist = _dist; }
public:
	void Moving();
private:
	float m_MoveAngle = 0.f;
	D3DXVECTOR3 m_dist;
	bool m_bMove = false;
};


#endif // !__CBIGMON_H__