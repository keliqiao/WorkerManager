#pragma once
#include "index.h"

class worker
{
public:
	//显示个人信息
	virtual void showinfo()=0;
	//获取岗位名称
	virtual string getDeptName()=0;
	//职工编号
	int id;
	//职工姓名
	string name;
	//职工所在部门编号
	int deptId;
};
