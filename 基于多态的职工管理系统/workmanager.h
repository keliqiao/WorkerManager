#pragma once//声明仅仅可以包含一次
#include "index.h"//包含主头文件
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include "fstream"
#define  FILENAME "empFile.txt"
class workmanager
{
public:
	workmanager();//构造函数
	~workmanager();//析构函数
	void showmenu();//展示菜单
	void exitsystem();//退出系统
	//记录文件中的人数个数
	int m_EmpNum;
	//员工数组的指针
	worker ** m_EmpArray;
	//添加员工
	void Add_Emp();
	//保存文件
	void save();
};
