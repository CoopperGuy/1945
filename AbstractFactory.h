#pragma once


#ifndef __ABSTRACTFACTORY_H__
#define __ABSTRACTFACTORY_H__

class CObj;
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
		if (FAILED(pObj->Initialize()))
		{
			Safe_Delete(pObj);
			return nullptr;
		}
		pObj->Set_Pos(_vPos);
		return pObj;
	}

};

#endif // !__ABSTRACTFACTORY_H__
#pragma once
