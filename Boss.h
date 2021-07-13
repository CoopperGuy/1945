#pragma once


#ifndef __CBOSS_H__
#define __CBOSS_H__

#include "Monster.h"
class CBoss :
	public CMonster
{
	enum PATTERN {P_ATTACK,P_ATTACK2_,P_MOVE,P_MOVEATK,P_END};
public:
	CBoss();
	virtual ~CBoss();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	void Attack_First();
	void Attack_Second();
	void BossMove();
	void BossMoveAttack();
private:
	DWORD m_PatternTime;
	DWORD m_PateernDelay;
	float m_fAngle = 0.f;
	float m_MoveAngle = 0.f;
	bool m_bPatternEnd = false;
	PATTERN m_ePattern = P_END;
};

#endif //__CBOSS_H__