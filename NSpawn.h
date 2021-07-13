#pragma once

#ifndef __CNSPAWN_H__
#define __CNSPAWN_H__

#include "Monster.h"
class CNSpawn :
	public CMonster
{
public:
	CNSpawn();
	virtual ~CNSpawn();

public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
private:
	DWORD m_SpwanTime;
	DWORD m_SpawnDelay;
	int Num_of_Spawn = 5;
};


#endif //__CNSPAWN_H__