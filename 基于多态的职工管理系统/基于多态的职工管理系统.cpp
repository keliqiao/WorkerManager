#include "index.h"
#include "workmanager.h"
#include "employee.h"
int main()
{
	workmanager wm;
	int choice;
	worker* wk=new Employee(1,"������",1);
	while (true)
	{
		wm.showmenu();
		cout<<"���ˣ�������ָ��"<<endl;
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
				break;
			}
		case 4://�޸�ְ��
			{
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