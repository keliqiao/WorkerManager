#include "employee.h"
void Employee::showinfo()
{
	cout<<"职工编号："<<id
	<<"\t职工姓名："<<name
	<<"\t岗位："<<getDeptName()
	<<"\t岗位职责：完成经理分配的任务"<<endl;
}
string Employee::getDeptName()
{
	return "员工";
}
Employee::Employee(int tid, string tname, int tdeptId)
{
	id=tid;
	name=tname;
	deptId=tdeptId;
}


