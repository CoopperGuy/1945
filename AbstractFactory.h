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

};

#endif // !__ABSTRACTFACTORY_H__
#pragma once
