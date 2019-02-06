#include <SFML/Network.hpp>
#include <thread>

sf::Socket::Status status;
std::thread receiver;
int main() {
	//status =
	sf::TcpListener listener;
	status = listener.listen(50000);
	sf::TcpSocket sock;
	status = listener.accept(sock);

	if (status == sf::Socket::Status::Done)
	{
		sock.send("Rawr", 4);
		char buffer[512];
		size_t br;
		sock.receive(buffer, 10, br);
	}

	return 0;
}