#include <iostream>
#include <iomanip>
#include <random>
#include <utility>
#include <cassert>
#include <chrono>

#include "array.h"
#include "quadratic_sort.h"
#include "nlogn_sort.h"
#include "linear_sort.h"
#include "search.h"

using namespace std;

int main() {
    const int range = 99;
    long int size = 1e5;
    cout << size << endl;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution dist(-range, range);
    bool (*comp_direct)(int, int) = cmp_less;
    bool (*comp_reversed)(int, int) = cmp_greater;

    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point finish;
    chrono::nanoseconds sorting_time;

    int array[size];
    for (int &i: array) {
        i = dist(mt);
    }
    int arr_to_sort[size];

    for (auto [sort, name]: {
            pair(bubble_sort, "bubble sort"), pair(insertion_sort, "insertion sort"),
            pair(merge_sort, "merge sort"), pair(quick_sort, "quick sort")
    })
        for (auto [reverse, comp]: {pair(false, comp_direct), pair(true, comp_reversed)}) {
            copy_array(array, arr_to_sort, size);
            start = chrono::steady_clock::now();
            sort(arr_to_sort, size, reverse, false);
            finish = chrono::steady_clock::now();
            sorting_time = chrono::duration_cast<chrono::nanoseconds>(finish - start);
            assert(is_sorted(arr_to_sort, size, comp));
            cout << setw(14) << left << name << ": " << setw(10) << right << sorting_time.count() << endl;
        }
    for (auto [reverse, comp]: {pair(true, comp_reversed), pair(false, comp_direct)}) {
        copy_array(array, arr_to_sort, size);
        start = chrono::steady_clock::now();
        counting_sort(arr_to_sort, size, range, reverse);
        finish = chrono::steady_clock::now();
        sorting_time = chrono::duration_cast<chrono::nanoseconds>(finish - start);
        assert(is_sorted(arr_to_sort, size, comp));
        cout << setw(16) << left << "counting sort : " << setw(11) << right << sorting_time.count() << endl;
    }

    for (int i: arr_to_sort)
        assert(i == arr_to_sort[binary_search(arr_to_sort, size, i)]);
}
