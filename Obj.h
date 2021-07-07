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

public:
	D3DXVECTOR3 Get_Pos() { return m_tInfo.vPos; }
	D3DXVECTOR3 Get_Size() { return m_tInfo.vSize; }
	D3DXVECTOR3 Get_Dir() { return m_tInfo.vDir; }
protected:
	D3DXVECTOR3 m_vQ[4];
	D3DXVECTOR3 m_vP[4];
	INFO m_tInfo;
	bool	m_bDead;
	float		m_fSpeed = 5.f;
	float		m_fAngle = 0.f;

};

#endif //__COBJ_H__