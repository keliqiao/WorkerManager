#include "boss.h"
void Boss::showinfo()
{
	cout<<"职工编号："<<id
	<<"\t职工姓名："<<name
	<<"\t岗位："<<getDeptName()
	<<"\t岗位职责：负责公司所有事务"<<endl;
}
string Boss::getDeptName()
{
	return (string)"老板";
}
Boss::Boss(int tid, string tname, int tdeptId)
{
	id=tid;
	name=tname;
	deptId=tdeptId;
}
