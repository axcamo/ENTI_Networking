#include "Online.h"

// -----------------------------------------
// CLIENT
// -----------------------------------------

void Online::Client::Init(std::string _ip, short _port)
{
	ip = _ip;
	port = _port;
}

void Online::Client::Run(CommunicationMode mode)
{
	switch (mode)
	{
	case Online::BLOCKING: {
		socket.connect(ip, port);
	}
						   break;
	case Online::NONBLOCKING: {

	}
							  break;
	default:
		break;
	}
}

// -----------------------------------------
// SERVER
// -----------------------------------------

Online::Server::Server()
{
	sockets = std::vector<sf::TcpSocket*>();
}

void Online::Server::Init(short _port)
{
	port = _port;
}

void Online::Server::Run(CommunicationMode mode)
{
	switch (mode)
	{
	case Online::BLOCKING:
	{
		std::thread listenThread(&Server::ThreadListen, this);
		listenThread.detach();
	}break;
	case Online::NONBLOCKING: 
	{

	}break;
	default:
		break;
	}
}

void Online::Server::SocketBehaviour()
{
	sf::Socket& sock = LastSocket();
	while (1) {
		std::cout << "Receiving..." << std::endl;
		
	}
}

void Online::Server::ThreadListen()
{
	while (1) {
		std::cout << "Listening..." << std::endl;
		if (listener.listen(port) == sf::Socket::Status::Done) {
			listener.accept(GenerateSocket());
			std::thread manageSocketThread(&Server::ManageSocket, this, LastSocketIndex());
			manageSocketThread.detach();
		}
	}

}

void Online::Server::ManageSocket(int sockIndex)
{
	sf::TcpSocket &sock = *sockets[sockIndex];
	sf::Packet packet;
	sock.receive(packet);
	std::cout << packet << std::endl;
}

sf::TcpSocket & Online::Server::LastSocket()
{
	return *sockets.back();
	// TODO: insertar una instrucción return aquí
}

int Online::Server::LastSocketIndex()
{
	return sockets.size() - 1;
}

sf::TcpSocket & Online::Server::GenerateSocket()
{
	sockets.push_back(new sf::TcpSocket());
	return *sockets.back();
	// TODO: insertar una instrucción return aquí
}