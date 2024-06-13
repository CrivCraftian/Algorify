#pragma once
#include "alpch.h"
#include "Algorify.h"

namespace Algorify
{
	static class Utilities
	{
	public:
		template<typename T> 
		static std::string AL_API VectorToString(const std::vector<T>& input);

		static std::vector<int> AL_API GenerateNumberSet(const int& count, const int& lowRange, const int& highRange);
	};
}
