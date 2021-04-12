#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[]){
	
	WSADATA wsa;	//holds additional data
	SOCKET s;		//create the socket

	//Initialise the Winsock library 

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Initialisation failed. Error Code : %d \n",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised.\n");

	//Create the socket

	if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_IP)) == INVALID_SOCKET){
		printf("Socket creation failed. Error Code : %d \n" , WSAGetLastError());
		return 1;
	}

	printf("Socket created.\n");

	// Program fails with error code 10013 - Permission Denied
}