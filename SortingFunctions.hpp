#include <vector>
#include <atomic>
#ifndef SORTINGFUNCTIONS_HPP
#define SORTINGFUNCTIONS_HPP

class SortingFunctions
{
public:		

	
	
	static void Mergesort(std::vector<int> &numbers);
	static void Mergesort(std::vector<int> &numbers, std::vector<int> &temparry, int left, int right);
	static void Merge(std::vector<int> &numbers, std::vector<int> &tempvector, int leftP, int rightP, int rightE);

	static void Heapsort(std::vector<int> &numbers);
	static inline int leftChild(int i);
	static void lookDown(std::vector<int> &numbers, int i, int vectorSize);

	static void Quicksort(std::vector<int> &numbers, int low, int high);
	static int median(std::vector<int> &numbers, int left, int center ,int right);
private:
	
	 
};
#endif // !SORTINGFUNCTIONS_HPP


