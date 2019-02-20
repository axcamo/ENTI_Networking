//#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <Online.h>

#define MAX_MENSAJES 30


int main()
{
	
	Online::Server* server = new Online::Server();
	server->Init(50000);
	server->Run(Online::CommunicationMode::BLOCKING);

	while (1);
}
