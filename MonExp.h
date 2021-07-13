#pragma once

#ifndef __CMONEXP_H__
#define __CMONEXP_H__

#include "Monster.h"
class CMonExp :
	public CMonster
{
public:
	CMonExp();
	virtual ~CMonExp();

	// CMonster을(를) 통해 상속됨
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	void Set_Dist(D3DXVECTOR3 _dist) { m_dist = _dist; }

private:
	float m_fRad;
	D3DXVECTOR3 m_dist;

};


#endif // !__CMONEXP_H__
