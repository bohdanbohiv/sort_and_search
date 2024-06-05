#include <utility>

#include "nlogn_sort.h"
#include "array.h"

using namespace std;

/*
 * array[0:mid] + array[mid:last+1] -> into[0:last+1]
 */
void merge(const int array[], long int mid, long int size, int into[], bool (* comp)(int, int)) {
    if (comp(array[mid], array[mid - 1]) || array[mid] == array[mid - 1]) {
        copy_array(array, into, size);
        return;
    }
    long int position = 0;
    long int left = 0;
    long int right = mid;
    while (left < mid && right < size)
        if (comp(array[left], array[right]))
            into[position++] = array[right++];
        else
            into[position++] = array[left++];
    while (left < mid)
        into[position++] = array[left++];
    while (right < size)
        into[position++] = array[right++];
}

int min(int a, int b) {
    return a > b ? b : a;
}

void merge_sort(int array[], long int size, bool reverse, bool debug) {
    if (debug)
        print_array(array, size);
    int auxiliary[size];
    int *aux = auxiliary;
    int *tmp;
    long int first;
    bool (* comp)(int, int);
    if (reverse)
        comp = cmp_less;
    else
        comp = cmp_greater;
    for (long int sub_size = 1; sub_size < size; sub_size *= 2) {
        tmp = array;
        array = aux;
        aux = tmp;
        for (first = 0; first < size; first += sub_size * 2)
            merge(aux + first, min(sub_size, size - first), min(2 * sub_size, size - first), array + first, comp);
        if (debug)
            print_array(array, size);
    }
    copy_array(array, aux, size);
}

long int partition(int array[], long int left, long int right, long int size, bool (* comp)(int, int), bool debug) {
    int pivot = array[left];
    long int i = left;
    long int j = right + 1;
    int tmp;
    while (true) {
        while (comp(array[++i], pivot) && i != right);
        while (comp(pivot, array[--j]) && j != left);
        if (i >= j)
            break;
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        if (debug)
            print_array(array, size);
    }
    tmp = array[j];
    array[j] = array[left];
    array[left] = tmp;
    if (debug)
        print_array(array, size);
    return j;
}

void quick_sort(int array[], long int first, long int last, long int size, bool (* comp)(int, int), bool debug) {
    if (last <= first)
        return;
    long int pivot = partition(array, first, last, size, comp, debug);
    quick_sort(array, first, pivot - 1, size, comp, debug);
    quick_sort(array, pivot + 1, last, size, comp, debug);
}

void quick_sort(int array[], long int size, bool reverse, bool debug) {
    bool (* comp)(int, int);
    if (reverse)
        comp = cmp_greater;
    else
        comp = cmp_less;
    if (debug)
        print_array(array, size);
    quick_sort(array, 0, size - 1, size, comp, debug);
}
