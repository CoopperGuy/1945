#pragma once

#ifndef __CSOLOMON_H__
#define __CSOLOMON_H__

#include "Monster.h"
class CSoloMon :
	public CMonster
{
public:
	CSoloMon();
	virtual ~CSoloMon();

public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CSOLOMON_H__
