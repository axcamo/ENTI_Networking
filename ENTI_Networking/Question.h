#pragma once
#include <string>

struct Question {
	std::string text;
	std::pair<std::string, int> responses[3];
};