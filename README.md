# 概要  
ネットワークエミュレータアプリをOS:windows(winsocket)で作成したい  


# コメント  
以前にもネットワークエミュレータアプリを作成しようとしたが、  
ws2tcpip.h　が見つけられなくて断念した。  

見つけた。
ws2tcpip.h が存在する場所  
C:\MinGW\include\ws2tcpip.h  

winsock.h が存在する場所  
C:\MinGW\include\winsock.h  

もしかしたらネットワークエミュレータを作成できるかもしれない  


# ヘッダー と ライブラリ の ファイルパス  
ヘッダーファイルパス：  
C:\MinGW\include  

ライブラリファイルパス：  
C:\MinGW\lib  


# トライしてみたこと

.\test.cpp  
```
#include <iostream>
using namespace std;

#include <winsock2.h>
#include <ws2tcpip.h>

int main(){
    std::cout << "Network Emulator2" << std::endl;


    if(1 == IP_OPTIONS){
        std::cout << "Network Emulator2" << std::endl;

    }

}
```

コンパイル  
g++ .\test.cpp  

実行結果  
.\a.exe  


# WinSock で簡易パケットキャプチャ
[参考] WinSock で簡易パケットキャプチャを作ろう  
https://www.keicode.com/windows/winsock-packet-capture.php  


# 注意 mstcpip.h を使う

winsocket では  
mstcpip.hヘッダーを利用する  

そのため、このヘッダーがある　開発環境が必要となる  

これまで使ってきた MinGW で存在しない  

調べてみたら、msys2 というC++環境では存在した  


サイト：  
MSYS2：Software Distribution and Building Platform for Windows  
https://www.msys2.org/  


Installation 手順：  
1. Download the installer: sys2-x86_64-20231026.exe　をダウンロードする  
2. Run the installer. MSYS2 requires 64 bit Windows 8.1 or newer.    
3. C:¥msys64 にインストールする  
4. UCRT64 environment という環境をインストールする  
5. C:\msys64　直下にある mingw64.exe を開くとターミナルが表示される。　もしかしたら他のアプリケーション ucrt64.exe でも問題ないかもしれない  
6. ターミナルで下記を実行する  
   1. pacman -S mingw-w64-ucrt-x86_64-gcc  
7. 確認  
   1. ライブラリ  
      1. C:\msys64\ucrt64\include  
      2. 下記のヘッダーがある  
         1. mstcpip.h  
         2. winsock2.h  
         3. ws2tcpip.h  
   2. コンパイラ  
      1. C:\msys64\ucrt64\bin  
      2. g++.exe が存在する  
8. 気になること  
   1. ライブラリの拡張子が .a .o ファイルであったこと  
      1. C:\msys64\ucrt64\lib  
      2. libasp.a  
9. C++ の 環境変数 をMinGW から msys2 に変更する  
   1.  下記を環境変数に追加する  
       1.  C:\msys64\ucrt64\bin  
   2.  MinGW　の bin フォルダのパスの名前を変更する  
       1.  例  
           1.  C:\MinGW\bin_  

コマンドプロンプトで下記を実行する  
PS C:\Users\sasak> g++ --version  
g++.exe (Rev2, Built by MSYS2 project) 13.2.0  
Copyright (C) 2023 Free Software Foundation, Inc.  
This is free software; see the source for copying conditions.  There is NO  
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  


MSYS2 となっているので問題はないかもしれない。。。  


test.cpp で #include <winsock2.h> 定義して コンパイルしたが、 byte の定義がないといわれて、コンパイルエラーがでていた。。。  

ただインクルードしただけで  
エラーが出るなんで。。。  

解決  
// using namespace std;  
コメントアウトしたら、ビルドのエラーがでなくなった。  


コンパイルのコマンド  
g++  .\test2.cpp -lws2_32  


[参考リンク]   
winsockの初期化  
WSAStartup、WSACleanup  
https://www.geekpage.jp/programming/winsock/wsastartup.php  


[参考リンク]  
WinSock で簡易パケットキャプチャを作ろう  
https://www.keicode.com/windows/winsock-packet-capture.php  


[参考リンク] API 説明  
socket 関数 (winsock2.h)  
SOCKET WSAAPI socket(  
  [in] int af,  
  [in] int type,  
  [in] int protocol
);


[参考リンク]  
C++でMACアドレスを取得する  
https://araramistudio.jimdo.com/2019/06/04/c-%E3%81%A7mac%E3%82%A2%E3%83%89%E3%83%AC%E3%82%B9%E3%82%92%E5%8F%96%E5%BE%97%E3%81%99%E3%82%8B/  

実行コマンド  
g++  .\test4.cpp -lws2_32 -luser32 -lIphlpapi  


[参考リンク]  
ネットワークインターフェースのIP情報を取得する  
https://www.geekpage.jp/programming/iphlpapi/ip-info.php  


[参考] Network Emulator for Windows Toolkit  
C:\Program Files\Network Emulator for Windows Toolkit\sdk\sample  

g++ .\sample\use_api.cpp -Iinclude -Llib -luserapi


PS C:\Program Files\Network Emulator for Windows Toolkit\sdk> g++ .\sample\use_api.cpp -Iinclude -Llib -luserapi  
In file included from .\sample\use_api.cpp:12:  
include/ne.h:24:8: warning: extra tokens at end of #endif directive [-Wendif-labels]  
   24 | #endif NEW_DRIVER  
      |        ^~~~~~~~~~  
include/ne.h:825:8: warning: extra tokens at end of #endif directive [-Wendif-labels]  
  825 | #endif NEW_DRIVER  
      |        ^~~~~~~~~~  
In file included from .\sample\use_api.cpp:13:  
include/nehlp.h:192:8: warning: extra tokens at end of #endif directive [-Wendif-labels]  
  192 | #endif NEW_DRIVER  
      |        ^~~~~~~~~~  
C:/msys64/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: cannot open output file a.exe: Permission denied  
collect2.exe: error: ld returned 1 exit status  
PS C:\Program Files\Network Emulator for Windows Toolkit\sdk>  

コマンドプロンプトを管理者権限で開いて、下記を実行するとエラーがなくなった  

g++ .\sample\use_api.cpp -Iinclude -Llib -luserapi  

a.exe を実行する
userapi.dll が見つからないというエラーがでた。
