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
	if (right - left > 1)
	{
		int midpoint = left + (right - left) / 2;

		MergeSort(arr, left, midpoint);
		MergeSort(arr, midpoint, right);

		Merge(arr, left, midpoint, right);

		return;
	}
}

void AL_API Algorify::Algorithms::MergeSort(std::vector<int>& arr)
{
	MergeSort(arr, 0, arr.size());
}

void Algorify::Algorithms::Merge(std::vector<int>& arr, const int& left, const int& mid, const int& right)
{
	std::vector<int> out(right - left);

	int lStep = left;
	int RStep = mid;
	int i = 0;

	while (lStep < mid && RStep < right)
	{
		if (arr[lStep] > arr[RStep])
		{
			out[i] = arr[RStep];
			RStep++;
		}
		else
		{
			out[i] = arr[lStep];
			lStep++;
		}

		i++;
	}

	while (lStep < mid)
	{
		out[i] = arr[lStep];
		lStep++;
		i++;
	}

	while (RStep < right)
	{
		out[i] = arr[RStep];
		RStep++;
		i++;
	}

	for (int i = left, k = 0; i < right; i++, k++)
	{
		arr[i] = out[k];
	}

	/*
	while (LStep != mid && RStep != right - mid + 1)
	{
		if (arr[left + LStep] > arr[mid + 1 + RStep])
		{
			arr[left + LStep] = arr[mid + 1 + RStep];
			LStep++;
		}
		else
		{
			RStep++;
		}
	}
	*/
}
