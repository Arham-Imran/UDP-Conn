#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <string.h>

#define PORT 5000
#define MAXLINE 1000 

int main() 
{ 
	char buffer[100]; 
	const char *message = "Hello Client"; 
	int listenfd, len; 
	struct sockaddr_in servaddr, cliaddr; 
	memset(&servaddr, 0, sizeof(servaddr)); 

	listenfd = socket(AF_INET, SOCK_DGRAM, 0);		 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 

	len = sizeof(cliaddr); 
	int n = recvfrom(listenfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr,(socklen_t*)&len);
	buffer[n] = '\0'; 
	puts(buffer); 
		
	sendto(listenfd, message, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
} 
