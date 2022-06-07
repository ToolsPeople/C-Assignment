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
		if (select == 1)//��ҳ
		{
			people->show();
			system("pause");
		}
		else if (select == 2)//��Ʊ
		{
			people->book_ticket();
		}
		else if (select == 3)//��Ʊ
		{
			people->refund_ticket();
		}
		else if (select == 4)
		{
			cout << "ע���ɹ���" << endl;
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
		cout << "                =======��ӭ���뺽����Ʊϵͳ�ͻ���=====" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t| ��ѡ�����Ĳ�����                   |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         1.ע���˺�                 |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         2.��½�˺�                 |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         0.�˳�ϵͳ                 |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "                ======================================" << endl;
		cin >> number;
		if (number == 1)
		{
			string filename;//�����ļ�����
			ofstream ofs;//�ļ���������
			filename = PASSENGER_FILE;
			ofs.open(filename, ios::out | ios::app);//����׷�ӵķ�ʽд�ļ���
			string key_word1, key_word2;
			string use_name;
			string true_name;
			string id;
			cout << "�����������û�����" << endl;
			cin >> use_name;
			cout << "������������ʵ������" << endl;
			cin >> true_name;
			cout << "�������������֤�ţ�" << endl;
			cin >> id;
			cout << "�������������룺" << endl;
			cin >> key_word1;
			cout << "���ٴ������������룺" << endl;
			cin >> key_word2;
			if (key_word1 == key_word2)  
			{
				ofs << use_name << " " << key_word1 << " " << true_name << " " << id << " " << endl;
				cout << "ע��ɹ���" << endl;
				ofs.close();
			}
			else
			{
				cout << "�����������벻һ�£�������ע�ᣡ" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (number == 2)
		{
			ifstream ifs;//������һ������
			string file_name;
			file_name = PASSENGER_FILE;
			ifs.open(file_name, ios::in);//���ļ�������
			if (!ifs.is_open())
			{
				cout << "�ļ�������!" << endl;
				ifs.close();
			}
			//׼�������û�����Ϣ��
			string name;//�û�����
			string pwd;//���룻
			string fname;//�ļ��洢������
			string fpwd;//�ļ��洢������
			string ft_name;//�ļ��洢����ʵ����
			string fid;//�ļ��洢�����֤��
			cout << "�����������û�����" << endl;
			cin >> name;
			cout << "�������������룺" << endl;
			cin >> pwd;
			//�˿������֤��
			while (ifs >> fname && ifs >> fpwd && ifs >> ft_name &&ifs >> fid)
			{
				if (name == fname && pwd == fpwd)
				{
					cout << "�˿���Ϣ��֤�ɹ���" << endl;
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
					//cout << "�������" << endl;
					//cout << "�����µ�¼��" << endl;
					//system("pause");
					//system("cls");
				}
			}
			
		}
		else if (number == 0)
		{
			cout << "�˳��ɹ���" << endl;
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
		else
		{	
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}