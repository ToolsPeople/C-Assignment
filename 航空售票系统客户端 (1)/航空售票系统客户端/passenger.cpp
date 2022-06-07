#include"passenger.h"
#include "tcpSocket.h"
#include <iostream>

void Passenger::show()//主页
{
	cout << "您的用户名为：" <<use_name <<endl;
	cout << "您的真实姓名为：" << true_name << endl;
	cout << "您的身份证号为：" << id << endl;
}

void Passenger::book_ticket()//订票
{
	init_Socket();

	SOCKET fd = createClientSocket();
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };


	cout << "已连接购票管理员..." << endl;
	while (true)
	{

		//发送消息
		cout << "send:";




		do
		{
			gets_s(sendbuf, BUFSIZ);
		} while (!sendbuf[0]);






		if (strcmp(sendbuf, "end") == 0) {
			cout << "结束对话" << endl;
			break;
		}




		if (send(fd, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			err("send");
			break;
		}


		//recv从指定的socket接受消息
		if (recv(fd, recvbuf, BUFSIZ, 0) > 0) {
			cout << "recv:" << recvbuf << endl;

			memset(recvbuf, 0, sizeof(recvbuf));
		}


	}

	closesocket(fd);
	close_Socket();
}
void Passenger::refund_ticket()//退票
{
	init_Socket();

	SOCKET fd = createClientSocket();
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };


	cout << "已连接退票管理员..." << endl;
	while (true)
	{
	
		//发送消息
		cout << "send:";




		do
		{
			gets_s(sendbuf, BUFSIZ);
		} while (!sendbuf[0]);
		
		
		


		
		if (strcmp(sendbuf, "end") == 0) {
			cout << "结束对话" << endl;
			break;
		}
		
		
		
		
		if (send(fd, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			err("send");
			break;
		}
		
		
		//recv从指定的socket接受消息
		if (recv(fd, recvbuf, BUFSIZ, 0) > 0) {
			cout << "recv:" << recvbuf << endl;

			memset(recvbuf, 0, sizeof(recvbuf));
		}
		

	}


	closesocket(fd);
	close_Socket();
}
void Passenger::openmenu()//子菜单；
{
	cout << "                =======操作页面====" << endl;
	cout << "\t\t|   1.主页        |\t\t" << endl;
	cout << "\t\t|   2.订票        |\t\t" << endl;
	cout << "\t\t|   3.退票        |\t\t" << endl;
	cout << "\t\t|   4.注销        |\t\t" << endl;
	cout << "                ===================" << endl;
}