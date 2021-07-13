#pragma once

#ifndef __CVMONSTER_H__
#define __CVMONSTER_H__

#include "Monster.h"
class CVMonster :
	public CMonster
{
public:
	CVMonster();
	virtual ~CVMonster();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	void Set_Dist(D3DXVECTOR3 _dist) { m_dist = _dist; }
private:
	float m_MoveAngle = 0.f;
	D3DXVECTOR3 m_dist;
	D3DXVECTOR3 m_vdir;
	bool m_bMove = false;
};


#endif // !__CVMONSTER_H__
