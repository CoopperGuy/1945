#pragma once
#ifndef __EXPLODEBULLET_H__
#define __EXPLODEBULLET_H__

#include "Monster.h"
class CExplodeBullet :
	public CMonster
{
public:
	CExplodeBullet();
	virtual ~CExplodeBullet();

	// Inherited via CMonster
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
private:
	float m_fAngle;

	DWORD dwExplodeTime;
	DWORD dwExplodeDelayTime;
};

#endif // !__EXPLODEBULLET_H__
