#include "alpch.h"
#include "Algorithms.h"

void AL_API Algorify::Algorithms::Testing()
{
	std::cout << "Projects are linked :)";

	for (auto i = 0; i < 100; i++)
	{
		std::cout << "YIPPEE" << "\n";
	}
}

void AL_API Algorify::Algorithms::BubbleSort(std::vector<int>& input)
{
	int n = input.size() - 1;

	for (auto i = 0; i < input.size()-1; i++)
	{
		bool swapped{ false };

		for (auto j = 0; j < n - i; j++)
		{
			if (input[j] >= input[j + 1])
			{
				std::swap(input[j], input[j + 1]);

				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

void AL_API Algorify::Algorithms::MergeSort(std::vector<int>& arr, const int left, const int right)
{
	// For tomorrow
	// Split array, then recersevely call the function
	// Then merge again
	if (left >= right)
	{
		return;
	}

	int midpoint = std::ceil((right + left) * 0.5f);

	MergeSort(arr, left, midpoint - 1);
	MergeSort(arr, midpoint, right);

	Merge(arr, left, midpoint, right);

	return void AL_API();
}

void Algorify::Algorithms::Merge(std::vector<int>& arr, const int& left, const int& mid, const int& right)
{
	std::vector<int> out;

	/*
	int i, j;

	while ()
	{

	}
	*/
}
