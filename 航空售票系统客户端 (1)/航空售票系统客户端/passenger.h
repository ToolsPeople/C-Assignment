#pragma once
#include<iostream>
#include<string>
using namespace std;
class Passenger
{
public:
	string password;//密码
	string use_name;//用户名
	string true_name;//真实姓名
	string id;//身份证号；
	Passenger(){}
	Passenger(string u_name, string t_name, string pwd, string id)
	{
		use_name.assign(u_name);
		true_name.assign(t_name);
		password.assign(pwd);
		this->id.assign(id);
	}
	void show();//查看主页；
	void book_ticket();//订票；
	void refund_ticket();//退票；
	void openmenu();//子菜单；

};
