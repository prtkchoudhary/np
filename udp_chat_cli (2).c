 #include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>

int main(){
char sendm[100];
char recvm[100];
struct sockaddr_in serveraddr;
serveraddr.sin_port=htons(12345);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr= inet_addr("127.0.0.1");
int sockfd=socket(AF_INET,SOCK_DGRAM,0);
int c=sizeof(serveraddr);
while(1){

printf("enter a msg Client:");
fgets(sendm,100,stdin);
sendto(sockfd,sendm,100,0,(struct sockaddr *)&serveraddr, c);
if(strcmp(sendm,"exit\n")==0){
break;
}

recvfrom(sockfd,recvm,100,0,(struct sockaddr *)&serveraddr,&c);
printf("got a msg server: %s",recvm);
if(strcmp(recvm,"exit\n")==0){
break;
}
}
}

