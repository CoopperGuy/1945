#pragma once


#ifndef __CBMONSPAWN_H__
#define __CBMONSPAWN_H__

#include "Monster.h"
class CBMonSpawn :
	public CMonster
{
public:
	CBMonSpawn();
	virtual ~CBMonSpawn();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	void Set_Dist(D3DXVECTOR3 _dist) { m_dist = _dist; }
private:
	DWORD m_SpwanTime;
	DWORD m_SpawnDelay;
	D3DXVECTOR3 m_dist;
	int Num_of_Spawn = 1;
	int Start_Num;
};


#endif // !__CBMONSPAWN_H__
