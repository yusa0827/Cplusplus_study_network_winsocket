#include <stdio.h>
#include <winsock2.h>

int main() {

	WSADATA wsaData;
	int err;

	err = WSAStartup(MAKEWORD(2,0), &wsaData);
	if (err != 0) {
		switch (err) {
			case WSASYSNOTREADY:
				printf("WSASYSNOTREADY\n");
				break;
			case WSAVERNOTSUPPORTED:
				printf("WSAVERNOTSUPPORTED\n");
				break;
			case WSAEINPROGRESS:
				printf("WSAEINPROGRESS\n");
				break;
			case WSAEPROCLIM:
				printf("WSAEPROCLIM\n");
				break;
			case WSAEFAULT:
				printf("WSAEFAULT\n");
				break;
		}
	}
	else {
		printf("WSAStartup\n");
	}

 	WSACleanup();

 	return 0;
}