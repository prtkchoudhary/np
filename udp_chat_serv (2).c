#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>

int main(){
char sendm[100];
char recvm[100];
struct sockaddr_in serveraddr,cli;
serveraddr.sin_port=htons(12345);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
int sockfd=socket(AF_INET,SOCK_DGRAM,0);
int c=sizeof(cli);
while(1){
bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));

recvfrom(sockfd,recvm,100,0,(struct sockaddr *)&cli,&c);
printf("got a msg client: %s\n enter msg server:",recvm);
fgets(sendm,100,stdin);
printf("waiting from client");
sendto(sockfd,sendm,100,0,(struct sockaddr *)&cli,c);
if(strcmp(sendm,"exit\n")==0){
break;
}
}
}

