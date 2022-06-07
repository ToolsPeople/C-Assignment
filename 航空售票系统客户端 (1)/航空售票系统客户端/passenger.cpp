#include"passenger.h"
#include "tcpSocket.h"
#include <iostream>

void Passenger::show()//��ҳ
{
	cout << "�����û���Ϊ��" <<use_name <<endl;
	cout << "������ʵ����Ϊ��" << true_name << endl;
	cout << "�������֤��Ϊ��" << id << endl;
}

void Passenger::book_ticket()//��Ʊ
{
	init_Socket();

	SOCKET fd = createClientSocket();
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };


	cout << "�����ӹ�Ʊ����Ա..." << endl;
	while (true)
	{

		//������Ϣ
		cout << "send:";




		do
		{
			gets_s(sendbuf, BUFSIZ);
		} while (!sendbuf[0]);






		if (strcmp(sendbuf, "end") == 0) {
			cout << "�����Ի�" << endl;
			break;
		}




		if (send(fd, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			err("send");
			break;
		}


		//recv��ָ����socket������Ϣ
		if (recv(fd, recvbuf, BUFSIZ, 0) > 0) {
			cout << "recv:" << recvbuf << endl;

			memset(recvbuf, 0, sizeof(recvbuf));
		}


	}

	closesocket(fd);
	close_Socket();
}
void Passenger::refund_ticket()//��Ʊ
{
	init_Socket();

	SOCKET fd = createClientSocket();
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };


	cout << "��������Ʊ����Ա..." << endl;
	while (true)
	{
	
		//������Ϣ
		cout << "send:";




		do
		{
			gets_s(sendbuf, BUFSIZ);
		} while (!sendbuf[0]);
		
		
		


		
		if (strcmp(sendbuf, "end") == 0) {
			cout << "�����Ի�" << endl;
			break;
		}
		
		
		
		
		if (send(fd, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			err("send");
			break;
		}
		
		
		//recv��ָ����socket������Ϣ
		if (recv(fd, recvbuf, BUFSIZ, 0) > 0) {
			cout << "recv:" << recvbuf << endl;

			memset(recvbuf, 0, sizeof(recvbuf));
		}
		

	}


	closesocket(fd);
	close_Socket();
}
void Passenger::openmenu()//�Ӳ˵���
{
	cout << "                =======����ҳ��====" << endl;
	cout << "\t\t|   1.��ҳ        |\t\t" << endl;
	cout << "\t\t|   2.��Ʊ        |\t\t" << endl;
	cout << "\t\t|   3.��Ʊ        |\t\t" << endl;
	cout << "\t\t|   4.ע��        |\t\t" << endl;
	cout << "                ===================" << endl;
}