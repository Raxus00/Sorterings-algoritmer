#include "SortingFunctions.hpp"

void SortingFunctions::Mergesort(std::vector<int>& numbers)
{
	std::vector<int>tempvector(numbers.size());

	Mergesort(numbers, tempvector, 0, numbers.size() - 1);
}

 void SortingFunctions::Mergesort(std::vector<int> &numbers, std::vector<int> &tempvector, int left, int right)
 {
	 if (left < right)
	 {
		 int center = (left + right) / 2;
		 Mergesort(numbers, tempvector, left, center);
		 Mergesort(numbers, tempvector, center + 1, right);
		 Merge(numbers, tempvector, left, center + 1, right);
	 }
 }
 void SortingFunctions::Merge(std::vector<int> &numbers, std::vector<int> &tempvector, int leftP, int rightP, int rightE)
 {
	 int leftE = rightP - 1;
	 int tempnumb = leftP;
	 int numberOfElements = rightE - leftP + 1;
	 while (leftP<= leftE && rightP <= rightE)
	 {
		 if (numbers[leftP] <= numbers[rightP])
		 {
			 tempvector[tempnumb++] = std::move( numbers[leftP++] );
		 }
		 else
		 {
			 tempvector[tempnumb++] = std::move(numbers[rightP++]);
		 }
	 }
	 while (leftP<=leftE)
	 {
		 tempvector[tempnumb++] = std::move(numbers[leftP++]);
	 }
	 while (rightP <= rightE)
	 {
		 tempvector[tempnumb++] = std::move(numbers[rightP++]);
	 }
	 for (int i = 0; i < numberOfElements; i++, rightE--)
	 {
		 numbers[rightE] = std::move(tempvector[rightE]);
	 }
 }


void SortingFunctions::Heapsort( std::vector<int> &numbers)
{
	for (int i = (numbers.size() / 2) - 1; i >= 0; i--)	
	{
		lookDown(numbers, i, numbers.size());
	}
	for (int j = numbers.size() - 1; j > 0; j--)
	{
		std::swap(numbers[0], numbers[j]);	
		lookDown(numbers, 0  , j);
	}
}

inline int SortingFunctions::leftChild(int i)
{
	 return (2 * i) + 1;
}

void SortingFunctions::lookDown(std::vector<int> &numbers, int i, int vectorSize)
{
	int Child;
	int numb;

	for (numb = std::move(numbers[i]); leftChild(i) < vectorSize; i = Child)	
	{
		Child = leftChild(i);
		if (Child != vectorSize - 1 && numbers[Child] < numbers[Child + 1])
		{
			Child++;
		}
		if (numb < numbers[Child])
		{
			numbers[i] = std::move(numbers[Child]);
		}
		else
		{
			break;
		}
	}
	numbers[i] = std::move(numb);
}

void SortingFunctions::Quicksort(std::vector<int> &numbers, int left, int right)
{
	int center = (left + right) / 2;
	int pivot = median(numbers, left, center, right);
	int i = left;
	int j = right;

	while (i < right|| j>left)
	{
		while (numbers[i] < pivot)
		{
			i++;
		}
		while (numbers[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(numbers[i], numbers[j]);
			i++;
			j--;

		}
		else
		{
			if (i < right)
			{
				Quicksort(numbers, i, right);
			}
			if (j > left)
			{
				Quicksort(numbers, left, j);
			}
			return;	
		}
		
	}
}

int SortingFunctions::median(std::vector<int> &numbers, int left, int center ,int right)
{
	if (numbers[center] < numbers[left])
	{
		std::swap(numbers[left], numbers[center]);
	}
	if (numbers[right] < numbers[left])
	{
		std::swap(numbers[left], numbers[right]);
	}
	if (numbers[right] < numbers[center])
	{
		std::swap(numbers[center], numbers[right]);
	}

	std::swap(numbers[center], numbers[right - 1]);
	return numbers[right - 1];
}