#include <iostream>
#include <functional>
#include <utility>


/**
 * @brief Generic SelectionSort implementation with Templates
 * 
 * @tparam T Type of elements to be sorted
 * @param array Array to be sorted
 * @param size Number of elements in the array
 * @param compare Custom comparison function (defaults to greater than)
 * @return true if the array was sorted, false if not sorted
 */

template <typename T>
bool SelectionSort(T array[], int size, std::function<bool(const T&, const T&)> compare = std::greater<T>()){

    // if something goes wrong return false
    if(!array || size <= 0) {
        return false;
    }
    // already sorted
    if (size == 1) {
        return true;
    }
    for(int i=0; i< size-1; i++){
        // keep an index of which array member has smallest variable in current itteration
        int index=i;
        for(int j=i+1; j<size; j++){
            if(compare(array[index], array[j])){
                index=j;
            }
        }
        std::swap(array[i], array[index]);

    }
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

    SelectionSort(intArr,n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}