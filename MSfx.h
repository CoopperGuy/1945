#pragma once

#ifndef __CMSFX_H__
#define __CMSFX_H__

#include "Obj.h"
class CMSfx :
	public CObj
{
public:
	CMSfx();
	virtual ~CMSfx();

public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
private:
	float m_fAngle = 0.f;

};


#endif // !__CMSFX_H__
