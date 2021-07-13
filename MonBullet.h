#pragma once


#ifndef __CMONBULLET_H__
#define __CMONBULLET_H__

#include "Monster.h"
class CMonBullet :
	public CMonster
{
public:
	CMonBullet();
	virtual ~CMonBullet();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready()override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CMONBULLET_H__
