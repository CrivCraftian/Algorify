#include "Algorify.h"
#include <chrono>
#include <vector>
#include <memory>
#include <set>

#define LOG(x) :: std::cout << x << "\n";

using namespace Algorify::DataStructures;
using namespace std;

int SearchRecursive(vector<int>& nums, int& target, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int midpoint = (start+(end-start) / 2);

	if (nums[midpoint] == target)
	{
		return midpoint;
	}

	if (target < nums[midpoint])
	{
		return SearchRecursive(nums, target, start, midpoint - 1);
	}
	else
	{
		return SearchRecursive(nums, target, midpoint + 1, end);
	}
}


int search(vector<int>& nums, int target) {
	return SearchRecursive(nums, target, 0, nums.size()-1);
}

// Q: I want to create a new project that uses the Algorify library. How do I do that?
// A: You need to link the Algorify library to your project. Here's how you do it:
// 1. Right-click on your project in the Solution Explorer and select Properties.
// 2. In the Properties window, go to Configuration Properties > C/C++ > General > Additional Include Directories.
// 3. Add the path to the Algorify library's include folder. For example, if your Algorify library is in C:\Algorify, you would add C:\Algorify\include.
// 4. Click OK to save the changes.
// 5. Next, go to Configuration Properties > Linker > General > Additional Library Directories.
// 6. Add the path to the Algorify library's lib folder. For example, if your Algorify library is in C:\Algorify, you would add C:\Algorify\lib.
// 7. Click OK to save the changes.
// 8. Finally, go to Configuration Properties > Linker > Input > Additional Dependencies.
// 9. Add the name of the Algorify library file. For example, if your Algorify library is named Algorify.lib, you would add Algorify.lib.
// 10. Click OK to save the changes.
// 11. Now you can include the Algorify library's header files in your project and use its functions and classes.

// Q: Is there not a more intuitive way to link the Algorify library to my project? It kinda feels like linking this way makes it dependant on the Alogrify library's location on my machine.
// A: Yes, there is a more intuitive way to link the Algorify library to your project. You can use a property sheet to manage the library dependencies. Here's how you do it:
// 1. Right-click on your project in the Solution Explorer and select Properties.
// 2. In the Properties window, go to Configuration Properties > C/C++ > General > Additional Include Directories.
// 3. Add the path to the Algorify library's include folder. For example, if your Algorify library is in C:\Algorify, you would add C:\Algorify\include.
// 4. Click OK to save the changes.
// 5. Next, go to Configuration Properties > Linker > General > Additional Library Directories.
// 6. Add the path to the Algorify library's lib folder. For example, if your Algorify library is in C:\Algorify, you would add C:\Algorify\lib.
// 7. Click OK to save the changes.

int main()
{
	LinkedList<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	LinkedList<int> nums2;

	for (int i = 0; i < nums.Size(); i++)
	{
		nums2.Prepend(nums[i]);
	}

	LOG(nums.ToString());
	LOG(nums2.ToString());
	LOG((nums == nums2 ? "true" : "false"));
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