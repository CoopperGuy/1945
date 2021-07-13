#pragma once

#ifndef __FINALBOSS_H__
#define __FINALBOSS_H__

#include "Monster.h"
class CFinalBoss :
	public CMonster
{
	enum PATTERN2 { ATTACK1, ATTACK2, ATTACK3, END };
public:
	CFinalBoss();
	virtual ~CFinalBoss();

	// Inherited via CMonster
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

public:
	//enum°ú ÀÏÄ¡
	void Attack1();
	void Attack2();
	void Attack3();
	void Attack_Movement();

private:
	DWORD m_PatternTime;
	DWORD m_PatternDelay;
	float m_fAngle = 0.f;
	float m_MoveAngle = 0.f;
	bool m_bPatternEnd;
	PATTERN2 m_ePattern;
};

#endif // !__FINALBOSS_H__
