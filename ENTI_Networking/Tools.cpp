#include "Tools.h"
#include <iostream>
#include <ctime>

void Tools::SafePrint(std::string message, std::mutex &mut)
{
	mut.lock();
	std::cout << message.c_str() << std::endl;
	mut.unlock();
}

std::string Tools::RandomizedText(std::vector<std::string> textList)
{
	std::srand(std::time(NULL));
	return textList[std::rand() % textList.size()];
}
