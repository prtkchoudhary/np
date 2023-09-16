#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#include<arpa/inet.h>

int main(){
char sendm[100];
char recvm[100];

int flag=1;
while(flag){
struct sockaddr_in serveraddr;
bzero(&serveraddr,sizeof(serveraddr));
serveraddr.sin_port=htons(22000);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
int sockfd=socket(AF_INET,SOCK_STREAM,0);
connect(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
printf("enter msg client: ");
fgets(sendm,100,stdin);
send(sockfd,sendm,100,0);
if(strcmp(sendm,"exit\n")==0){
break;
}
recv(sockfd,recvm,100,0);
printf("server : %s ",recvm);
if(strcmp(recvm,"exit\n")==0){
flag=0;
}
}
}

