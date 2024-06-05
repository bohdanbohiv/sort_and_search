#include <iostream>

#include "linear_sort.h"
#include "array.h"

using namespace std;

void increment(long int *number) {
    ++(*number);
}

void decrement(long int *number) {
    --(*number);
}

void counting_sort(int array[], long int size, int range, bool reverse, bool debug) {
    int counts[2 * range + 1];
    for (int i = 0; i <= 2 * range; ++i)
        counts[i] = 1;
    if (debug) {
        cout << "array:\n";
        print_array(array, size);
        cout << "counts:\n";
        print_array(counts, 2 * range + 1);
    }
    for (long int i = 0; i < size; ++i) {
        ++counts[array[i] + range];
        if (debug)
            print_array(counts, 2 * range + 1);
    }

    long int j;
    void (*next)(long int *);
    if (reverse) {
        j = size - 1;
        next = decrement;
    } else {
        j = 0;
        next = increment;
    }

    if (debug)
        cout << endl;
    int number;
    for (int i = 0; i <= 2 * range; ++i)
        for (number = i - range; --counts[i]; next(&j)) {
            array[j] = number;
            if (debug) {
                cout << "counts\n";
                print_array(counts, 2 * range + 1);
                cout << "array\n";
                print_array(array, size);
                cout << endl;
            }
        }
}
