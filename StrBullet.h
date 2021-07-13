#pragma once

#ifndef __CSTRBULLET_H__
#define __CSTRBULLET_H__

#include "Monster.h"
class CStrBullet :
	public CMonster
{
public:
	CStrBullet();
	virtual ~CStrBullet();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CSTRBULLET_H__
