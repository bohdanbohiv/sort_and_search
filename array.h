#ifndef INC_2_SORT_SEARCH_ARRAY_H
#define INC_2_SORT_SEARCH_ARRAY_H

void copy_array(const int source[], int destination[], long int size);
void print_array(const int array[], long int size);
bool is_sorted(int array[], long int size, bool (* comp)(int, int));

#endif //INC_2_SORT_SEARCH_ARRAY_H
