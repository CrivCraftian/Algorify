#pragma once

#include "alpch.h"
#include "Algorify.h"

namespace Algorify
{
	static class Algorithms
	{
	public:
		static void AL_API Testing();
		static void AL_API BubbleSort(std::vector<int>& input);
		static void AL_API MergeSort(std::vector<int>& arr, const int left, const int right);
		static void AL_API MergeSort(std::vector<int>& arr);

	private:
		static void Merge(std::vector<int>& arr, const int& left, const int& mid, const int& right);
	};
}
