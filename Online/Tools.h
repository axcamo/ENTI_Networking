#include <mutex>
#include <vector>

namespace Tools {
	void SafePrint(std::string message, std::mutex &mut);
	std::string RandomizedText(std::vector<std::string> textList);
	inline double Clamp(double value, double min, double max)
	{
		return (value < min) ? min : (value > max) ? max : value;
	}
	inline double Map(double value, double inMin, double inMax, double outMin, double outMax) {
		return outMin + (outMax - outMin) * (value - inMin) / (inMax - inMin);
	}
}