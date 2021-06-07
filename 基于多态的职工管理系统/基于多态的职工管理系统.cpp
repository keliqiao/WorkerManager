#include "index.h"
#include "workmanager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	workmanager wm;
	int choice;
	while (true)
	{
		wm.showmenu();
		cout<<"主人，请输入指令吧"<<endl;
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
				wm.Add_Emp();
				break;
			}
		case 2://显示职工
			{
			wm.showemp();
				break;
			}
		case 3://删除职工
			{
			wm.delemp();
				break;
			}
		case 4://修改职工
			{
			wm.modifyworker();
				break;
			}
		case 5://查找职工
			{
			wm.findemp();
				break;
			}
		case 6://排序职工
			{
			wm.sortemp();
				break;
			}
		case 7://清空文件
			{
			wm.cleanfiles();
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