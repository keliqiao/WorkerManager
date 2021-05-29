#pragma once
#include "index.h"
#include "worker.h"

class Boss:public worker
{
public:
	Boss(int tid,string tname,int tdeptId);
	//显示个人信息
	virtual void showinfo();
	//获取岗位名称
	virtual string getDeptName();
};