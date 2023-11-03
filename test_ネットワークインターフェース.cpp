#include <stdio.h>

#include <winsock2.h>
#include <iphlpapi.h>

int
main()
{
 int i;
 PIP_INTERFACE_INFO pInfo = NULL;
 ULONG ulOutBufLen = 0;
 DWORD dwRetVal = 0;

 /* 変数 ulOutBufLen に必要なサイズを取得 */
 if (GetInterfaceInfo(NULL, &ulOutBufLen)
       == ERROR_INSUFFICIENT_BUFFER) {
   pInfo = (IP_INTERFACE_INFO *) malloc (ulOutBufLen);
 }

 /* 実際にデータを取得する */
 dwRetVal = GetInterfaceInfo(pInfo, &ulOutBufLen);

 if (dwRetVal == NO_ERROR ) {
   printf("Number of Adapters: %ld\n\n", pInfo->NumAdapters);

   for (i=0; i<pInfo->NumAdapters; i++) {
     printf("Adapter Name: %ws\n", pInfo->Adapter[i].Name);
     printf("Adapter Index: %ld\n", pInfo->Adapter[i].Index);
     printf("\n");
   }
 } else {
   printf("GetInterfaceInfo failed.\n");
   LPVOID lpMsgBuf;
		
   if (FormatMessage(
           FORMAT_MESSAGE_ALLOCATE_BUFFER | 
           FORMAT_MESSAGE_FROM_SYSTEM | 
           FORMAT_MESSAGE_IGNORE_INSERTS,
           NULL,
           dwRetVal,
           MAKELANGID(LANG_NEUTRAL,
                      SUBLANG_DEFAULT), /* Default language */
           (LPTSTR) &lpMsgBuf,
           0,
           NULL ))  {
     printf("Error: %s", lpMsgBuf);
   }

   LocalFree( lpMsgBuf );
 }

 return 0;
}
