#include "alpch.h"
#include "Utilities.h"

namespace Algorify 
{
	template<typename T>
	std::string AL_API Utilities::VectorToString(const std::vector<T>& input)
	{
		std::ostringstream output;

		for (const T& v : input)
		{
			output << v << ", ";
		}

		output << "\n ";

		return output.str();
	}
	
	template std::string AL_API Utilities::VectorToString<int>(const std::vector<int>& input);
	template std::string AL_API Utilities::VectorToString<std::string>(const std::vector<std::string>& input);

	std::vector<int> AL_API Utilities::GenerateNumberSet(const int& count, const int& lowRange, const int& highRange)
	{
		std::random_device rd;

		std::mt19937 gen(rd());

		std::uniform_int_distribution<> dis(lowRange, highRange);

		std::vector<int> NewSet(count);

		for(int& i : NewSet)
		{
			i = dis(gen);
		}

		return NewSet;
	}
}