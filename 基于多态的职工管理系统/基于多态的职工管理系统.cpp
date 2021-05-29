#include "index.h"
#include "workmanager.h"
#include "employee.h"
int main()
{
	workmanager wm;
	int choice;
	worker* wk=new Employee(1,"葛瑞雨",1);
	while (true)
	{
		wm.showmenu();
		cout<<"主人，请输入指令"<<endl;
		cin>>choice;
		switch (choice)
		{
		case 0://退出系统
			{
				wm.exitsystem();
				break;
			}
		case 1: //添加职工
			{
				break;
			}
		case 2://显示职工
			{
				wk->showinfo();
				delete wk;
				break;
			}
		case 3://删除职工
			{
				break;
			}
		case 4://修改职工
			{
				break;
			}
		case 5://查找职工
			{
				break;
			}
		case 6://排序职工
			{
				break;
			}
		case 7://清空文件
			{
				break;
			}
		default:
			{
				system("cls");
				break;
			}
		}
	}
	system("pause");
	return 0;
}