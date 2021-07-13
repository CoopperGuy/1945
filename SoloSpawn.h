#pragma once

#ifndef __CSOLOSPAWN_H__
#define __CSOLOSPAWN_H__

#include "Monster.h"
class CSoloSpawn :
	public CMonster
{
public:
	CSoloSpawn();
	virtual ~CSoloSpawn();

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
	int Start_Num;
};


#endif // !__CSOLOSPAWN_H__
