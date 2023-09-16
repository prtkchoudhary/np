#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>

int main(){
char sendm[100];
char recvm[100];

struct sockaddr_in serveraddr;
bzero(&serveraddr,sizeof(serveraddr));
serveraddr.sin_port=htons(22000);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
int sockfd=socket(AF_INET,SOCK_STREAM,0);
int flag=1;
while(flag){
bind(sockfd, (struct sockaddr *)&serveraddr,sizeof(serveraddr));
listen(sockfd,10);
int comm=accept(sockfd,(struct sockaddr *)NULL,NULL);
recv(comm,recvm,100,0);
printf("client : %s ",recvm);
printf("enter msg server: ");
fgets(sendm,100,stdin);
if(strcmp(sendm,"exit\n")==0){
flag=0;
}
send(comm,sendm,100,0);
close(comm);
}

}


