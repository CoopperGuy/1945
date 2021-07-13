#pragma once

#ifndef __CBOSSBULLET_H__
#define __CBOSSBULLET_H__

#include "Monster.h"
class CBossBullet :
	public CMonster
{
public:
	CBossBullet();
	virtual ~CBossBullet();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CBOSSBULLET_H__
