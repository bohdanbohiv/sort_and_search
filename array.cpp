#include <iostream>

#include "array.h"

using namespace std;

void copy_array(const int source[], int destination[], long int size) {
    for (long int i = 0; i < size; i++)
        destination[i] = source[i];
}

void print_array(const int array[], long int size) {
    cout << '[';
    for (long int i = 0; i < size - 1; i++)
        cout << array[i] << ", ";
    cout << array[size - 1] << "]\n";
}

bool is_sorted(int array[], long int size, bool (* comp)(int, int)) {
    for (long int i = 0; i < size - 1; ++i)
        if (comp(array[i + 1], array[i]))
            return false;
    return true;
}
