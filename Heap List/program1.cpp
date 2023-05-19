#include "program1.h"
#include <vector>
#include <iostream>

int maxValue = 0;
// We can compensate with the array list method by using the formula: Parent(i) = return (i-2)/2. Needs a bit of work but it's a good starting place for 4 children per node.

std::vector<int> heapList;
std::vector<int> priorityList;

void printList() {
	std::cout << "\n" << "heapList: ";
	for (int i = 0; i < heapList.size(); i++) {
		std::cout << heapList.at(i) << " ";
	}
	std::cout << "\n" << "priority: ";
	for (int i = 0; i < priorityList.size(); i++) {
		std::cout << priorityList.at(i) << " ";
	}
}

// Heaplist size-1 because it is the last index, since the vector list starts at 0.
int getFirstChild(int parentIndex) {
	if (((parentIndex + 1) * 4) - 3 > heapList.size() - 1) {
		return -1;
	}
	return ((parentIndex + 1) * 4) - 3;
}

int getSecondChild(int parentIndex) {
	if (((parentIndex + 1) * 4) - 2 > heapList.size() - 1) {
		return -1;
	}
	return ((parentIndex + 1) * 4) - 2;
}

int getThirdChild(int parentIndex) {
	if (((parentIndex + 1) * 4) - 1 > heapList.size() - 1) {
		return -1;
	}
	return ((parentIndex + 1) * 4) - 1;
}
int getFourthChild(int parentIndex) {
	if (((parentIndex + 1) * 4) > heapList.size() - 1) {
		return -1;
	}
	return ((parentIndex + 1) * 4);
}

void swapVals(int firstIndex, int secondIndex) {
	int dummyVal = 0;
	// Value swap.
	dummyVal = heapList[firstIndex];
	heapList[firstIndex] = heapList[secondIndex];
	heapList[secondIndex] = dummyVal;
	// Priority swap
	dummyVal = priorityList[firstIndex];
	priorityList[firstIndex] = priorityList[secondIndex];
	priorityList[secondIndex] = dummyVal;
}

void maxHeapify(int headOfHeap) {
	// These initialized values are the indexes, not the actual values.
	int firstChild = getFirstChild(headOfHeap);
	int secondChild = getSecondChild(headOfHeap);
	int thirdChild = getThirdChild(headOfHeap);
	int fourthChild = getFourthChild(headOfHeap);
	int largestVal = heapList[headOfHeap];
	int largestIndex = headOfHeap;

	// Check if the children exceeds the array.
	// Then check if the value is greater than the parent.
	if (firstChild != -1 && heapList[firstChild] > heapList[headOfHeap]) {
		largestVal = heapList[firstChild];
		largestIndex = firstChild;
	}
	if (secondChild != -1 && heapList[secondChild] > largestVal) {
		largestVal = heapList[secondChild];
		largestIndex = secondChild;
	}
	if (thirdChild != -1 && heapList[thirdChild] > largestVal) {
		largestVal = heapList[thirdChild];
		largestIndex = thirdChild;
	}
	if (fourthChild != -1 && heapList[fourthChild] > largestVal) {
		largestVal = heapList[fourthChild];
		largestIndex = fourthChild;
	}
	// Call maxHeapify on the index of the original largest child.

	// Replace the new value with the old one to switch their places.
	if (largestVal != heapList[headOfHeap]) {
		swapVals(largestIndex, headOfHeap);
		maxHeapify(largestIndex);
	}
}

int getParent(int childIndex) {
	return(childIndex + 1) / 4;
	//return ((childIndex+4)/4)-1;
}

void heapSort() {
	int lastParentIndex = getParent(heapList.size());
	//std::cout << "\n" << "Your lastParentIndex is: " << lastParentIndex << "\n";
	for (int i = lastParentIndex; i > -1; i--) {
		maxHeapify(i);
	}
}

// Resets the heap to be empty.
void EmptyHeap() {
	heapList.clear();
}

// Adds a job to the heap with the specified priority.
void AddJob(int priority) {
	if (priority > 0) {
		priorityList.push_back(0);
		heapList.push_back(priority);
		if (heapList.size() > 1) {
			heapSort();
		}
	}
}
// Removes the job at the top of the heap and returns its priority.
int GetJob() {
	if (heapList.size() > 0) {
		for (int i = 0; i < priorityList.size(); i++) {
			if (priorityList[i] > 4) {
				heapList[i] = heapList[i] + 2;
				heapSort();
			}
		}
		int frontVal = heapList[0];
		heapList.erase(heapList.begin());
		priorityList.erase(priorityList.begin());
		if (heapList.size() > 0) {
			heapSort();
		}
		for (int i = 0; i < priorityList.size(); i++) {
			priorityList[i] = priorityList[i] + 1;
		}
		return frontVal;
	}
	else {
		return NO_JOB;
	}
}

// A recursive call that identifies the depth of the maxheap through finding how many parents it has.
int findTotalParents(int parentIndex, int totalParents) {
	if (getParent(parentIndex) > 0) {
		totalParents++;
		findTotalParents(getParent(parentIndex), totalParents);
	}
	return totalParents;
}

// Returns the depth of the first job found with the specified priority.
int GetDepth(int priority) {
	for (int i = 0; i < heapList.size(); i++) {
		if (heapList[i] == priority && i == 0) { // Change back i == 0 if it doesn't work out.
			return 0;
		}
		else if (heapList[i] == priority && i <= 4 && i > 0) {
			return 1;
		}
		else if (heapList[i] == priority && i > 4) {
			return findTotalParents(i, 0) + 1;
		}
	}
	return NO_DEPTH;
}

// Returns the priority of the job with the specified index.
int GetPriority(int index) {
	if (index < 1 || index > heapList.size()) {
		return NO_PRIORITY;
	}
	else {
		return heapList[index - 1];
	}
}