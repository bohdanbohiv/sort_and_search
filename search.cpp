#include "search.h"

long int binary_search(const int array[], long int size, int value) {
    long int left = 0;
    long int right = size - 1;
    for (long int middle; left <= right;) {
        middle = (left + right) / 2;
        if (value < array[middle])
            right = middle - 1;
        else if (array[middle] == value)
            return middle;
        else
            left = middle + 1;
    }
    return -1;
}
