#include <iostream>
#include <functional>
#include <utility>
#include <cmath>

/**
 * @brief Generic QuickSort implementation with Templates
 * 
 * @tparam T Type of elements to be sorted
 * @param array Array to be sorted
 * @param left First index of array
 * @param right Last index of array
 * @param compare Custom comparison function (defaults to greater than)
 * @return true if the array was sorted, false if not sorted
 */

template <typename T>
int Partition(T array[], int left, int right, std::function<bool(const T&, const T&)> compare = std::greater<T>()){
    
    int i=left-1,j=left-1;
    
    while(i<right-1){
        i++;
        if(!compare(array[i],array[right])){ // is array[i] <= right ?
            j++;
            if(i>j){
                std::swap(array[i],array[j]);
            }
        }
    }
    std::swap(array[j+1],array[right]);
    return j + 1;
}

template <typename T>

    
bool QuickSort(T array[], int left, int right, std::function<bool(const T&, const T&)> compare = std::greater<T>()){
    if (left >= right) return true;
    int pivot = Partition(array, left, right, compare);
    QuickSort(array,left,pivot-1, compare);
    QuickSort(array,pivot+1,right, compare);
    return true;
}


// simple intger array test
int main() {
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    QuickSort(intArr,0,n-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}