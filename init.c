#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

void ProcessPacket(unsigned char*, int);

int main(int argc , char *argv[])
{
	WSADATA wsa;	//holds additional data
	SOCKET s;		//create the socket
	struct sockaddr_in server;
	//struct addr_in in;
	//int total=0; tcp=0, udp=0; icmp=0, igmp=0, other=0;
	
	unsigned char *buffer = (unsigned char *)malloc(65536);

	//Initialise the Winsock library 

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Initialisation failed. Error Code : %d \n",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised.\n");

	//Create the socket

	if ((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET){
		printf("Socket creation failed. Error Code : %d \n" , WSAGetLastError());
		return 1;
	}

	printf("Socket created.\n");

	//Connect to server

	server.sin_addr.s_addr = inet_addr("192.168.20.19");
	server.sin_family = AF_INET;
	server.sin_port = htons( 2000 );

	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0){
		printf("Failed to connect to server. :( \n");
		return 1;
	}

	printf("Successfully connected to server :D \n");

	//while(1)
	//{
	//	saddr_size = sizeof saddr;
	//	data_size = recvfrom(s , buffer , 65536 , 0 , &saddr , &saddr_size);
	//	ProcessPacket(buffer, data_size);
	//}

	//close(s);
	//printf("Done");

	return 0;
}

//void ProcessPacket(unsigned char* buffer, int size){
//	struct iphdr *iph = (struct iphdr*)buffer;
//	++total;

//}