#pragma once
#include<iostream>
#include<string>
using namespace std;
class Passenger
{
public:
	string password;//����
	string use_name;//�û���
	string true_name;//��ʵ����
	string id;//���֤�ţ�
	Passenger(){}
	Passenger(string u_name, string t_name, string pwd, string id)
	{
		use_name.assign(u_name);
		true_name.assign(t_name);
		password.assign(pwd);
		this->id.assign(id);
	}
	void show();//�鿴��ҳ��
	void book_ticket();//��Ʊ��
	void refund_ticket();//��Ʊ��
	void openmenu();//�Ӳ˵���

};
