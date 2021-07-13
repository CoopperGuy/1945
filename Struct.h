#pragma once
#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vDir;
	D3DXVECTOR3 vSize;
	//D3DXVECTOR2; 
	//D3DXVECTOR4; //x,y,z,w
}INFO;

typedef struct tagObjInfo {
	tagObjInfo(int _hp, int _atk, float _spd, float _agl) :ihp(_hp),iatk(_atk),fspd(_spd), fagl(_agl){

	}
	int ihp;
	int iatk;
	float fspd;
	float fagl;
}OBJINFO;

#endif // !__STRUCT_H__
