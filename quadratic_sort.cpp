#include <utility>

#include "array.h"
#include "quadratic_sort.h"

using namespace std;

void bubble_sort(int array[], long int size, bool reverse, bool debug) {
    if (debug)
        print_array(array, size);

    bool (*comp)(int, int);
    if (reverse)
        comp = cmp_less;
    else
        comp = cmp_greater;
    int tmp;
    long int new_n, i;
    for (long int n = size; n > 1; n = new_n) {
        new_n = 1;
        for (i = 1; i < n; ++i) {
            if (comp(array[i - 1], array[i])) {
                tmp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = tmp;
                new_n = i;
            }
            if (debug)
                print_array(array, size);
        }
    }
}

void insertion_sort(int array[], long int size, bool reverse, bool debug) {
    if (debug)
        print_array(array, size);

    bool (*comp)(int, int);
    if (reverse)
        comp = cmp_greater;
    else
        comp = cmp_less;

    long int first = 0;
    for (long int i = 1; i < size; ++i)
        if (comp(array[i], array[first]))
            first = i;
    if (first != 0) {
        array[first] += array[0];
        array[0] = array[first] - array[0];
        array[first] -= array[0];
    }
    if (debug)
        print_array(array, size);

    int key;
    for (long int i = 1, j; i < size; ++i) {
        key = array[i];
        for (j = i - 1; comp(key, array[j]); --j)
            array[j + 1] = array[j];
        array[j + 1] = key;
        if (debug)
            print_array(array, size);
    }
}
