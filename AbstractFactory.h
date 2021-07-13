#pragma once


#ifndef __ABSTRACTFACTORY_H__
#define __ABSTRACTFACTORY_H__

class CObj;
class CMonster;
class CBigMon;
class CBMonSpawn;
template <typename T>
class CAbstractFactory {
public:
	static CObj* Create() {
		CObj* pObj = new T;
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		return pObj;
	}
	static CObj* Create(D3DXVECTOR3 _vPos) {
		CObj* pObj = new T;
		pObj->Set_Pos(_vPos);
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		return pObj;
	}
	static CObj* Create(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDir) {
		CObj* pObj = new T;
		pObj->Set_Pos(_vPos);
		pObj->Set_Dir(_vDir);
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}

		return pObj;
	}
	static CObj* Create(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDir, D3DXVECTOR3 _vDist) {
		CObj* pObj = new T;
		static_cast<T*>(pObj)->Set_Dist(_vDist);
		pObj->Set_Pos(_vPos);
		pObj->Set_Dir(_vDir);

		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		return pObj;
	}
	static CObj* Create(D3DXVECTOR3 _vPos,DWORD _delay ,int _Cnt) {
		CObj* pObj = new T;
		static_cast<CMonster*>(pObj)->Set_Cnt(_Cnt);
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		pObj->Set_Pos(_vPos);
		pObj->Set_Delay(_delay);
		return pObj;
	}
	static CObj* Create(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDir , DWORD _delay, int _Cnt) {
		CObj* pObj = new T;
		static_cast<CMonster*>(pObj)->Set_Cnt(_Cnt);
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		pObj->Set_Pos(_vPos);
		pObj->Set_Dir(_vDir);
		pObj->Set_Delay(_delay);
		return pObj;
	}
	static CObj* Create(D3DXVECTOR3 _vPos,  D3DXVECTOR3 _vDir, D3DXVECTOR3 _vDist, DWORD _delay, int _Cnt) {
		CObj* pObj = new T;
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		pObj->Set_Pos(_vPos);
		pObj->Set_Dir(_vDir);
		pObj->Set_Delay(_delay);
		static_cast<CBigMon*>(pObj)->Set_Cnt(_Cnt);
		static_cast<CBMonSpawn*>(pObj)->Set_Dist(_vDist);
		return pObj;
	}

};

#endif // !__ABSTRACTFACTORY_H__
#pragma once
