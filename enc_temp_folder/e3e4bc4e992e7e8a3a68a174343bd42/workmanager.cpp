#include "workmanager.h"
//构造函数
workmanager::workmanager()
{
	//记录文件中的人数个数
	m_EmpNum=0;
	//员工数组的指针
	m_EmpArray=NULL;
}
//析构函数
workmanager::~workmanager()
{
	if (m_EmpArray!=NULL)
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
	operfile.open("FILENAME", ios::out);
	for (int i=0;i<m_EmpNum;i++)
	{
		operfile << m_EmpArray[i]->id << " "
			<< m_EmpArray[i]->name << " "
			<< m_EmpArray[i]->deptId << endl;
	}
	operfile.close();
}
