#include "manager.h"
void Manager::showinfo()
{
	cout<<"职工编号："<<id
	<<"\t职工姓名："<<name
	<<"\t岗位："<<getDeptName()
	<<"\t岗位职责：辅助老板直接对老板负责"<<endl;
}
string Manager::getDeptName()
{
	return (string)"经理";
}
Manager::Manager(int tid, string tname, int tdeptId)
{
	id=tid;
	name=tname;
	deptId=tdeptId;
}

