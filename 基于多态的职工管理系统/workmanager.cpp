﻿#include "workmanager.h"
//构造函数
workmanager::workmanager()
{
	fstream tempfilestream;
	tempfilestream.open(FILENAME, ios::in);
	fileopenstate = tempfilestream.is_open();
	//文件不存在时
	if (!fileopenstate)
	{
		cout << "本地无数据文件" << endl;
		//记录文件中的人数个数
		m_EmpNum = 0;
		//员工数组的指针
		m_EmpArray = NULL;
		tempfilestream.close();
		return;
	}else
	//文件存在时
	{
		char tempchar;
		tempfilestream >> tempchar;
		if (tempfilestream.eof())
		{
			cout << "文件为空" << endl;
			m_EmpArray = NULL;
			m_EmpNum = 0;
			fileopenstate = false;
			tempfilestream.close();
			return;
		}else//当文件不为空时
		{
			int tenum;
			tenum=getfilepeonum();
			m_EmpNum = tenum;
			cout << "当前文件中的总人数为：" << m_EmpNum << endl;
			m_EmpArray = getfiledata();
			for (int inum=0;inum<m_EmpNum;inum++)
			{
				cout << m_EmpArray[inum]->id << " "
					<< m_EmpArray[inum]->name << " "
					<< m_EmpArray[inum]->deptId << endl;
			}
			
			
		}
	}
	
}
//析构函数
workmanager::~workmanager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}
//展示菜单
void workmanager::showmenu()
{
	cout << "===========================================" << endl;
	cout << "=********  欢迎使用职工管理系统！*********=" << endl;
	cout << "=************  0.退出管理程序  ***********=" << endl;
	cout << "=************  1.增加职工信息  ***********=" << endl;
	cout << "=************  2.显示职工信息  ***********=" << endl;
	cout << "=************  3.删除离职职工  ***********=" << endl;
	cout << "=************  4.修改职工信息  ***********=" << endl;
	cout << "=************  5.查找职工信息  ***********=" << endl;
	cout << "=************  6.按照编号排序  ***********=" << endl;
	cout << "=************  7.清空所有文档  ***********=" << endl;
	cout << "===========================================" << endl;
	cout << endl;
}
//退出系统
void workmanager::exitsystem()
{
	cout<<"欢迎下次使用"<<endl;
	exit(0);
}
//添加职工
void workmanager::Add_Emp()
{
	cout<<"请输入要添加的员工数：";
	int addNum = 0;
	todo1:
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		worker ** newSpace = new worker*[newSize];

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" ;
			cin >> id;
			cout << "您输入的是：" << id << endl;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "您输入的是：" << name << endl;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			todo2:
			cin >> dSelect;
			cout << "您输入的是：" << ((dSelect == 1) ? "普通职工" : (dSelect == 2) ? "经理" : (dSelect == 3) ? "老板" : "非法输入") << endl;
			if (dSelect!=1&&dSelect!=2 && dSelect!=3)
			{
				cout << "请重新输入：";
				goto todo2;
			}
			worker * wr = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				wr = new Employee(id, name, 1);
				break;
			case 2: //经理
				wr = new Manager(id, name, 2);
				break;
			case 3:  //老板
				wr = new Boss(id, name, 3);
				break;
			default:
				cout << "非法输入！";
				break;
			}
			newSpace[m_EmpNum+i]=wr;
		}
		delete[] m_EmpArray;
		m_EmpArray=newSpace;
		m_EmpNum=newSize;
		fileopenstate = true;
		cout << "成功添加" << addNum << "个员工" << endl;
	}else
	{
		cout<<"非法输入，请输入大于零的数字：";
		goto todo1;
	}
	save();
	system("pause");
	system("cls");
}
void workmanager::save()
{
	fstream operfile;
	operfile.open(FILENAME, ios::out);
	for (int i=0;i<m_EmpNum;i++)
	{
		operfile << m_EmpArray[i]->id << " "
			<< m_EmpArray[i]->name << " "
			<< m_EmpArray[i]->deptId << endl;
	}
	operfile.close();
}
int workmanager::getfilepeonum()
{
	int teid;
	string tename;
	int tedid;
	fstream temfilestream;
	temfilestream.open(FILENAME, ios::in);
	int gnum = 0;
	while (temfilestream>>teid&&temfilestream>>tename&&temfilestream>>tedid)
	{
		gnum++;
	}
	return gnum;
}
worker** workmanager::getfiledata()
{
	
	worker** temwork = new worker * [m_EmpNum];
	fstream filestreamtem;
	filestreamtem.open(FILENAME, ios::in);
	int tid;
	string tname;
	int tdid;
	int num = 0;
	worker* workt;
	while (filestreamtem >> tid && filestreamtem >> tname && filestreamtem >> tdid)
	{
		if (tdid == 1)
		{
			workt = new Employee(tid, tname, tdid);
		}
		else if (tdid == 2)
		{
			workt = new Manager(tid, tname, tdid);
		}
		else
		{
			workt = new Boss(tid, tname, tdid);
		}
		temwork[num] = workt;
		num++;
	}
	filestreamtem.close();
	return temwork;
}
void workmanager::showemp()
{
	if (fileopenstate)
	{
		for (int ie=0;ie<m_EmpNum;ie++)
		{
			m_EmpArray[ie]->showinfo();
		}
	}else
	{
		cout << "文件不存在或者本地无记录" << endl;
	}
	system("pause");
	system("cls");
}
int workmanager::returnexsitnum(int workid)
{
	for (int i=0;i<m_EmpNum;i++)
	{
		if (workid==m_EmpArray[i]->id)
		{
			return i;
		}
	}
	return -1;
}

void workmanager::delemp()
{
	if(fileopenstate)
	{
		cout << "请输入要删除工人的ID：";
		int id;
		cin >> id;
		for (int i=returnexsitnum(id);i+1<m_EmpNum;i++)
		{
			m_EmpArray[i] = m_EmpArray[i + 1];
		}
		m_EmpNum--;
		save();
		cout << "已删除并保存到文件" << endl;
	}else
	{
		cout << "记录为空或者文件不存在" << endl;
	}
	system("pause");
	system("cls");
	return;
}



