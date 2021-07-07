#pragma once

#ifndef __CBULLET_H__
#define __CBULLET_H__

#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet();
	virtual ~CBullet();
public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CBULLET_H__
