#pragma once

#ifndef __COBJ_H__
#define __COBJ_H__

class CObj
{
public:
	CObj();
	virtual ~CObj();

	virtual HRESULT Initialize() = 0;
	virtual int Update() = 0;
	virtual void Late_Update() = 0;
	virtual void Render(HDC _DC) = 0;
	virtual void Release() = 0;
public:
	void Set_Pos(D3DXVECTOR3 _vPos) { m_tInfo.vPos = _vPos; }
	void Set_Size(D3DXVECTOR3 _vSize) { m_tInfo.vSize = _vSize; }
	void Set_Dir(D3DXVECTOR3 _vDir) { m_tInfo.vDir = _vDir; }
	void Set_Dead() { m_bDead = true; }
	void Set_Time(DWORD _dt) { m_dwTime = _dt; }
	void Set_Delay(DWORD _dt) { m_dwDelayTime = _dt; }
	void Set_Hp(int _dmg) { m_tObjInfo.ihp += _dmg; }
public:
	const D3DXVECTOR3& Get_Pos() const { return m_tInfo.vPos; }
	D3DXVECTOR3 Get_Pos_NoRefernece()  { return m_tInfo.vPos; }
	const D3DXVECTOR3& Get_Size() const { return m_tInfo.vSize; }
	const D3DXVECTOR3& Get_Dir() const { return m_tInfo.vDir; }
	const int& Get_Dmg() const { return m_tObjInfo.iatk; }
protected:
	D3DXVECTOR3 m_vQ[4];
	D3DXVECTOR3 m_vP[4];
	INFO m_tInfo;
	OBJINFO m_tObjInfo;
	DWORD m_dwTime;
	DWORD m_dwDelayTime;
	bool	m_bDead;


};

#endif //__COBJ_H__