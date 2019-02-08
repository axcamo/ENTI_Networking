#include <SFML/Network.hpp>
#include <thread>
#include <iostream>
#include <mutex>
#include "Tools.h"
#include "Question.h"

sf::Socket::Status status;
char inputData;
std::mutex printerMutex;

std::vector<Question> questions;
int currentQuestionIndex;
int globalPoints;


static bool ProgramShouldClose() {
	return inputData == 'q';
}

void MudAmbientLooper() {
	sf::Clock c;

	while (!ProgramShouldClose()) {
		if (c.getElapsedTime().asSeconds() >= 5) {
			c.restart();
			Tools::SafePrint(Tools::RandomizedText(std::vector<std::string>{
				"Who's that pokemooon!?",
				"It's Pikachuuu!",
				"FUUUUUUCK!",
				"Oh look! That's a tree...",
				"I love you...",
				"You're hungry",
				"U want some poo?"
			}), printerMutex);
		}
	}
}

void ManageSystemMessages() {
	sf::Clock c;

	while (!ProgramShouldClose())
	{
		if (c.getElapsedTime().asSeconds() >= 2) {
			c.restart();
			Tools::SafePrint(Tools::RandomizedText(std::vector<std::string>{
				"Paco disconnected.",
				"Alex joined",
				"Juanjo died",
				"Carmen joined",
				"A dog just joined",
				"Wtf man!?"
			}), printerMutex);
		}
	}
}

void CheckResponseValidity(Question q) {
	globalPoints += q.responses[(int)inputData].second;
}

Question &GetCurrentQuestion() {
	return questions[currentQuestionIndex];
}

void ManageInputs() {
	std::cin >> inputData;
	CheckResponseValidity(GetCurrentQuestion());
}

int main() {
	//std::thread mudAmbientThread(&MudAmbientLooper);
	//std::thread systemMessagesThread(&ManageSystemMessages);

	std::thread questionsThread(&ManageInputs);
	while (!ProgramShouldClose()) {
		//std::cout << "Insert a command:\nSee Room (d)\nMove (n, s, e, w)\nExit (q)\n->";

		//switch (inputData)
		//{
		//case 'd': {
		//	std::cout << "Command sent to server." << std::endl;
		//}break;
		//case 'n': {
		//	std::cout << "Command sent to server." << std::endl;
		//}break;
		//case 's': {
		//	std::cout << "Command sent to server." << std::endl;
		//}break;
		//case 'e': {
		//	std::cout << "Command sent to server." << std::endl;
		//}break;
		//case 'w': {
		//	std::cout << "Command sent to server." << std::endl;
		//}break;
		//case 'q': {

		//}break;
		//default: {
		//	std::cout << "[ERROR] Please, input a valid command." << std::endl;
		//}break;
		//}
	}

	//mudAmbientThread.join();
	//systemMessagesThread.join();

	return 0;
}

