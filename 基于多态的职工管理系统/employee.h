#pragma once
#include "index.h"
#include "worker.h"

class Employee:public worker
{
public:
	//显示个人信息
	virtual void showinfo();
	//获取岗位名称
	virtual string getDeptName();
	//构造函数
	Employee(int tid, string tname, int tdeptId);
};
