#include "index.h"
#include "workmanager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	workmanager wm;
	int choice;
	worker* wk=new Employee(1,"������",1);
	worker* ma=new Manager(2,"�ۿ���",2);
	worker* bo=new Boss(3,"Kaid",3);
	while (true)
	{
		wm.showmenu();
		cout<<"���ˣ�������ָ���"<<endl;
		cin>>choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			{
				wm.exitsystem();
				break;
			}
		case 1: //���ְ��
			{
				break;
			}
		case 2://��ʾְ��
			{
				wk->showinfo();
				delete wk;
				break;
			}
		case 3://ɾ��ְ��
			{
				ma->showinfo();
				delete ma;
				break;
			}
		case 4://�޸�ְ��
			{
				bo->showinfo();
				delete bo;
				break;
			}
		case 5://����ְ��
			{
				break;
			}
		case 6://����ְ��
			{
				break;
			}
		case 7://����ļ�
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