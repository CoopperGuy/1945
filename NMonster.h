#pragma once

#ifndef __CNMONSTER_H__
#define __CNMONSTER_H__

#include "Monster.h"
class CNMonster :
	public CMonster
{
public:
	CNMonster();
	virtual ~CNMonster();

public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CNMONSTER_H__
