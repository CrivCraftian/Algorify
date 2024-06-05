#include "Algorify.h"
#include <chrono>
#include <vector>
#include <memory>

#define LOG(x) :: std::cout << x << "\n";

int main()
{
	std::vector<int> randNums = Algorify::Utilities::GenerateNumberSet(10000, 1, 10000);

	LOG("Before: " + Algorify::Utilities::VectorToString<int>(randNums));

	auto BigNumberList = std::shared_ptr<std::vector<int>>();

	// Algorithm
	auto start = std::chrono::high_resolution_clock::now();
	Algorify::Algorithms::BubbleSort(randNums);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	LOG("After: " + Algorify::Utilities::VectorToString<int>(randNums));
	
	LOG("Bubble sort took: " << duration.count() << "ms")

	return 0;
}