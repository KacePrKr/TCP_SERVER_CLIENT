

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

int main(){
////////////////////////////////////////////////////////////////////////////////////////////////////

    int clientSocket, returnSocket; //ပထမဆုံး Client အတွက်ရယ် Return ပြန်ဖို့အတွက်ရယ်ကို Socket တစ်ခု Declaration လုပ်ပေးထား
    struct sockaddr_in serverAddr;
    char buffer[1024];  // Buffer size 1024 sample  = latency 21.3ms


////////////////////////////////////////////////////////////////////////////////////////////////////

/*socketတစ်ခု စလုပ်ေတာ့မယ်ဆို
 *
 *
 */

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0){
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Client Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ////////////////////////////////////////////////////////////////////////////////////////////////

    returnSocket = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(returnSocket < 0){
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Connected to Server.\n");

    while(1){
        printf("Send To Server     : ");
        scanf("%s", &buffer[0]);
        send(clientSocket, buffer, strlen(buffer), 0);

        if(strcmp(buffer, "Exit") == 0){
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
            exit(1);
        }

        if(recv(clientSocket, buffer, 1024, 0) < 0){
            printf("[-]Error in receiving data.\n");
        }else{
            printf("Return From Server : %s\n", buffer);
        }
    }

    return 0;
}
