#include<iostream>
#include<string>
#include<fstream>
#include"passenger.h"
#include"globalfile.h"
#include "tcpSocket.h"
using namespace std;
void Passengermenu(Passenger * &people)
{
	while (true)
	{
		people->openmenu();
		int select = 0;
		cin >> select;
		if (select == 1)//主页
		{
			people->show();
			system("pause");
		}
		else if (select == 2)//订票
		{
			people->book_ticket();
		}
		else if (select == 3)//退票
		{
			people->refund_ticket();
		}
		else if (select == 4)
		{
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
int main()
{
	int number;
	while (true)
	{
		cout << "                =======欢迎进入航空售票系统客户端=====" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t| 请选择您的操作：                   |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         1.注册账号                 |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         2.登陆账号                 |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         0.退出系统                 |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "                ======================================" << endl;
		cin >> number;
		if (number == 1)
		{
			string filename;//操作文件名；
			ofstream ofs;//文件操作对象；
			filename = PASSENGER_FILE;
			ofs.open(filename, ios::out | ios::app);//利用追加的方式写文件；
			string key_word1, key_word2;
			string use_name;
			string true_name;
			string id;
			cout << "请输入您的用户名：" << endl;
			cin >> use_name;
			cout << "请输入您的真实姓名：" << endl;
			cin >> true_name;
			cout << "请输入您的身份证号：" << endl;
			cin >> id;
			cout << "请输入您的密码：" << endl;
			cin >> key_word1;
			cout << "请再次输入您的密码：" << endl;
			cin >> key_word2;
			if (key_word1 == key_word2)  
			{
				ofs << use_name << " " << key_word1 << " " << true_name << " " << id << " " << endl;
				cout << "注册成功！" << endl;
				ofs.close();
			}
			else
			{
				cout << "两次密码输入不一致，请重新注册！" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (number == 2)
		{
			ifstream ifs;//创建了一个对象；
			string file_name;
			file_name = PASSENGER_FILE;
			ifs.open(file_name, ios::in);//读文件操作；
			if (!ifs.is_open())
			{
				cout << "文件不存在!" << endl;
				ifs.close();
			}
			//准备接受用户的信息；
			string name;//用户名；
			string pwd;//密码；
			string fname;//文件存储的名字
			string fpwd;//文件存储的密码
			string ft_name;//文件存储的真实姓名
			string fid;//文件存储的身份证号
			cout << "请输入您的用户名：" << endl;
			cin >> name;
			cout << "请输入您的密码：" << endl;
			cin >> pwd;
			//乘客身份验证；
			while (ifs >> fname && ifs >> fpwd && ifs >> ft_name &&ifs >> fid)
			{
				if (name == fname && pwd == fpwd)
				{
					cout << "乘客信息验证成功！" << endl;
					system("pause");
					system("cls");
					Passenger *person = NULL;
					person = new Passenger(fname, ft_name, fpwd, fid);
					Passengermenu(person);
					system("pause");
					system("cls");
				}
				else
				{
					//cout << "密码错误！" << endl;
					//cout << "请重新登录！" << endl;
					//system("pause");
					//system("cls");
				}
			}
			
		}
		else if (number == 0)
		{
			cout << "退出成功！" << endl;
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
		else
		{	
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}