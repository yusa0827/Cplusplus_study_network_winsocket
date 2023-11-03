
// #include <iostream>
// using namespace std;
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mstcpip.h>

// IP structure.
// see. Gary R. Wright et al,
//  "TCP/IP Illustrated, Vol 2" p.211, Addison Wesley, 1995

typedef struct IP_HEADER {
	unsigned char ip_vhl; // version and header length
#define ip_v ip_vhl>>4
#define ip_hl ip_vhl&0x0F
	unsigned char ip_tos; // type of service
	unsigned short ip_len; // total length
	unsigned short ip_id; // identification
	unsigned short ip_off; //fragment offset field
#define IP_DF 0x4000 //dont fragment flag
#define IP_MF 0x2000 //more fragment flag
#define IP_OFFMASK 0x1fff //mask for fragmenting bits
	unsigned char ip_ttl; // time to live
	unsigned char ip_p; //protocol
	unsigned short ip_sum; // checksum
	struct in_addr ip_src, ip_dst; // source and dest address
} IP_HEADER, *PIP_HEADER;



typedef struct TCP_HEADER {
	unsigned short th_sport; // 16-bit source port number
	unsigned short th_dport; // 16-bit destination port number
	unsigned long th_seq; // 32-bit sequence number
	unsigned long th_ack; // 32-bit acknowledgement number
	unsigned char th_hlr; // header length and reserved
	unsigned char th_rfl; // reserved and flags
#define th_hl th_hlr>>4
#define th_flags th_rfl&0x3F
	unsigned short th_win; // 16-bit window size
	unsigned short th_sum; // 16-bit TCP checksum
	unsigned short th_urp; // 16-bit urgent offset
} TCP_HEADER, *PTCP_HEADER;


typedef struct MY_TCPROW {
	DWORD dwState;
	in_addr LocalAddr;
	SHORT sLocalPort;
	in_addr RemoteAddr;
	SHORT sRemotePort;
} MY_TCPROW, *PMY_TCPROW;

WSADATA g_wsaData;

int main(){
    // std::cout << "Network Emulator2" << std::endl;


    if(9 == IP_MULTICAST_IF){
        // std::cout << "Network Emulator2" << std::endl;

    }


	INT i, nRet, nNIC;
	char szBuff[4096], *lpNIC;
	DWORD dwBytesReturned;
	SOCKET_ADDRESS_LIST* sock_addr_list;
	SOCKADDR_IN *nic_addr, addr;
	ULONG uRCVALL_OPTION = RCVALL_ON;


	IP_HEADER ip_header;
	TCP_HEADER tcp_header;
	DWORD dwTotalHeaderLen;
	char* lpBuffer;


	WSADATA wsaData;

	// WSAStartup
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	WSACleanup();

	return 0;

}

