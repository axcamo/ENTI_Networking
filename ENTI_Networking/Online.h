#pragma once
#include <SFML/Network.hpp>
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
namespace Online {
	
	enum CommunicationMode {BLOCKING, NONBLOCKING};

	class Server {
	public:
		Server();
		void Init(short _port);
		void Run(CommunicationMode mode);

	private:

		void SocketBehaviour();

		void ThreadListen();
		void ManageSocket(int sockIndex);

		sf::TcpSocket &LastSocket();
		int LastSocketIndex();

		sf::TcpSocket &GenerateSocket();

		short port;

		sf::TcpListener listener;
		std::vector<sf::TcpSocket*> sockets;
	};

	class Client {
	public:
		void Init(std::string _ip, short _port);
		void Run(CommunicationMode mode);
	private:
		std::string ip;
		short port;
		sf::TcpSocket socket;
	};
}