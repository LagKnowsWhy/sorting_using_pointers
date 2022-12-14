#include "sorting.h"

int main(){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;

    srand (time(NULL));
    int n = 100;
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
    int *arr2 = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr2[i] = rand() % 100;
    }
    cSorting sort;
    std::cout << "Bubble sort:\nUnsorted array: ";
    sort.printArray(arr, n);

    auto bubble_t1 = high_resolution_clock::now();
    sort.bubbleSort(arr, n);
    auto bubble_t2 = high_resolution_clock::now();

    std::cout << "Sorted array: ";
    sort.printArray(arr, n);

    std::cout << "Bubblesort time taken: " << bubble_t2.time_since_epoch().count() - bubble_t1.time_since_epoch().count() << "ms \n\n";


    std::cout << "Quick sort:\nUnsorted array: ";
    sort.printArray(arr2, n);

    auto quick_t1 = high_resolution_clock::now();
    sort.quickSort(arr2, n, 0, n - 1);
    auto quick_t2 = high_resolution_clock::now();
    
    std::cout << "Sorted array: ";
    sort.printArray(arr2, n);

    std::cout << "Quicksort time taken: " << quick_t2.time_since_epoch().count() - quick_t1.time_since_epoch().count() << "ms \n";

    return 0;
}