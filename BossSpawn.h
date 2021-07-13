#pragma once

#ifndef __CBOSSSPAWN_H__
#define __CBOSSSPAWN_H__

#include "Monster.h"
class CBossSpawn :
	public CMonster
{
public:
	CBossSpawn();
	virtual ~CBossSpawn();

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
	int Num_of_Spawn = 1;

};


#endif //__CBOSSSPAWN_H__