#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

#define PORT 5000 
#define MAXLINE 1000 

int main() 
{ 
	char buffer[100]; 
	const char *message = "Hello Server"; 
	int sockfd, n; 
	struct sockaddr_in servaddr; 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

	sendto(sockfd, message, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
	
	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL); 
	puts(buffer); 

	close(sockfd); 
} 
