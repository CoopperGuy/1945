#pragma once

#ifndef __CEXPLOSION_H__
#define __CEXPLOSION_H__

#include "Obj.h"
class CExplosion :
	public CObj
{
public:
	CExplosion();
	virtual ~CExplosion();

public:
	virtual HRESULT Initialize() override;
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


#endif // !__CEXPLOSION_H__
