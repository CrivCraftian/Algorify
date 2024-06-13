#include "Algorify.h"
#include <chrono>
#include <vector>
#include <memory>

#define LOG(x) :: std::cout << x << "\n";

int findPeakElement(std::vector<int>& nums)
{
	auto isPeak = [&](int i) -> bool {
		bool leftSmaller = (i == 0) || (nums[i] > nums[i - 1]);
		bool rightSmaller = (i == nums.size() - 1) || (nums[i] > nums[i + 1]);
		return leftSmaller && rightSmaller;
		};

	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (isPeak(i))
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	std::vector<int> iNumbers = { 5, 8, 15, 37, 43, 95, 76, 92 };

	/*
	Algorify::DataStructures::BinaryTree<int> bt;
	*/

	Algorify::DataStructures::LinkedList<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto& i : iNumbers)
	{
		// nums.Append(i);
	}

	/*
	LOG(bt.Search(37));
	*/

	nums.Remove(2);
	nums.Remove(2);
	nums.Remove(2);

	LOG(nums.ToString());
	LOG(nums[2]);

	return 0;
}

//
	/*
	std::vector<int> randNums = Algorify::Utilities::GenerateNumberSet(100000, 1, 100000);

	LOG("Before: " + Algorify::Utilities::VectorToString<int>(randNums));

	auto BigNumberList = std::shared_ptr<std::vector<int>>();

	// Algorithm
	auto start = std::chrono::high_resolution_clock::now();
	Algorify::Algorithms::MergeSort(randNums);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	LOG("After: " + Algorify::Utilities::VectorToString<int>(randNums));

	LOG("Merge sort took: " << duration.count() << "ms")
	*/