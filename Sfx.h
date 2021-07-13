#pragma once

#ifndef __CSFX_H__
#define __CSFX_H__

#include "Obj.h"
class CSfx :
	public CObj
{
public:
	CSfx();
	virtual ~CSfx();

public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
private:
	float m_fAngle = 0.f;
};

#endif //__CSFX_H__