#include <iostream>
#include <functional>
#include <utility>


/**
 * @brief Generic BubbleSort implementation with Templates
 * 
 * @tparam T Type of elements to be sorted
 * @param array Array to be sorted
 * @param size Number of elements in the array
 * @param compare Custom comparison function (defaults to greater than)
 * @return true if the array was sorted, false if not sorted
 */
template <typename T>
bool BubbleSort(T array[], int size, std::function<bool(const T&, const T&)> compare = std::greater<T>()){


    // if something goes wrong return false
    if(!array || size <= 0) {
        return false;
    }
    // already sorted
    if (size == 1) {
        return true;
    }
    // use a "swapped" boolean to see if a swap actually took place
    bool swapped = false;
    for (int itteration = 0;itteration < size -1 ; itteration++) {
        swapped = false;
        for (int index = 0;index < size - 1; index++){
            if (compare(array[index] , array[ index + 1 ])){ 
                std::swap(array[index], array[index + 1]);
                swapped = true;
            }
            
        }
        if (!swapped) {
            break;
        }
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

    BubbleSort(intArr,n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}