#include "stdafx.h"
#include "PatternMgr.h"
#include "ObjMgr.h"
#include "Player.h"
#include "Boss.h"
#include "BigMon.h"
#include "Item.h"
#include "NSpawn.h"
#include "NSpawnTwo.h"
#include "BMonSpawn.h"
#include "SoloSpawn.h"
#include "VSpawn.h"
#include "BossSpawn.h"
CPatternMgr::CPatternMgr()
{
}


CPatternMgr::~CPatternMgr()
{
}

void CPatternMgr::Pattern_A(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDir,DWORD _time , int _Cnt)//직선으로 가는 몬스터 5개 생성 대각선으로 가는것도 만들 수 있음
{
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNSpawn>::Create(_vPos, _vDir, _time, _Cnt), OBJID::MONSTERSPAWN);
}

void CPatternMgr::Pattern_B(D3DXVECTOR3 _vPos, DWORD _time, int _Cnt )//대각선으로 생성되는 몬스터
{
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNSpawnTwo>::Create(_vPos, { 0.f,1.f,0.f }, _time, _Cnt), OBJID::MONSTERSPAWN);
}

void CPatternMgr::Pattern_C(DWORD _time, int _Cnt)//큰놈 3개 생성 (지정위치 상관없이감)
{
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBMonSpawn>::Create({ -100.f,50.f,0.f }, { 0.f, 1.f, 0.f }, {200.f,200.f,0.f},_time, _Cnt), OBJID::MONSTERSPAWN);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBMonSpawn>::Create({ 300.f,-75.f,0.f }, { 0.f, 1.f, 0.f }, { 300.f,150.f,0.f }, _time, _Cnt), OBJID::MONSTERSPAWN);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBMonSpawn>::Create({ 600.f,50.f,0.f }, { 0.f, 1.f, 0.f }, { 400.f,200.f,0.f }, _time, _Cnt), OBJID::MONSTERSPAWN);

}

void CPatternMgr::Pattern_D(D3DXVECTOR3 _vPos, DWORD _time, int _Cnt)//1개가 위에서 아래로 떨어짐.
{
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CSoloSpawn>::Create(_vPos, { 0.f, 1.f, 0.f }, _time, _Cnt), OBJID::MONSTERSPAWN);
}

void CPatternMgr::Pattern_E(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDist, DWORD _time, int _Cnt)//v자로 이동하는 대각선이동 몬스터 5개 생성함.
{
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CVSpawn>::Create(_vPos, { 0.f, 0.f, 0.f }, _vDist, _time, _Cnt), OBJID::MONSTERSPAWN);
}


void CPatternMgr::Pattern_F(DWORD _time, int _Cnt)
{
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBossSpawn>::Create({250.f,150.f,0.f}, _time, _Cnt), OBJID::MONSTERSPAWN);
}