// Search.cpp

#include "Search.h"

// Recursive function to find the last occurrence of a target in a vector
int recursiveLastOccurrence(const std::vector<int>& vec, int target, int index) {
    if (index < 0) {  // Base case: reached the start of the vector
        return -1;    // Return -1 if the target is not found
    }

    if (vec[index] == target) {
        return index; // Return the current index if the target is found
    }

    // Recursive call moving one step back in the vector
    return recursiveLastOccurrence(vec, target, index - 1);
}
