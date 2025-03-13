#include <iostream>
#include <functional>
#include <utility>
#include <cmath>

/**
 * @brief Generic MergeSort implementation with Templates
 * 
 * @tparam T Type of elements to be sorted
 * @param array Array to be sorted
 * @param left First index of array
 * @param right Last index of array
 * @param compare Custom comparison function (defaults to greater than)
 * @return true if the array was sorted, false if not sorted
 */

template <typename T>
void Merge(T array[], int left, int middle, int right, std::function<bool(const T&, const T&)> compare = std::greater<T>()){

    // Calculate sizes of subarrays
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;
    
    // Create temp arrays - need dynamic allocation
    T* leftArray = new T[sizeLeft];
    T* rightArray = new T[sizeRight];
    
    // Copy data to temp arrays
    for (int i = 0; i < sizeLeft; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeRight; j++)
        rightArray[j] = array[middle + 1 + j];
    
    // pointers to leftArray;m rightArray and array indexes
    int i = 0,j = 0,k = left;

    while (i < sizeLeft && j < sizeRight){
        if(compare(rightArray[j], leftArray[i])){
            array[k]=leftArray[i];
            i++;
        } else {
            array[k]=rightArray[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeft) {
        array[k]=leftArray[i];
        i++;
        k++;  
    }     
        
    while (j < sizeRight) {
        array[k]=rightArray[j];
        j++;
        k++;  
    }

    delete[] leftArray;
    delete[] rightArray;

}

template <typename T>
bool MergeSort(T array[], int left, int right, std::function<bool(const T&, const T&)> compare = std::greater<T>()){

    if (left >= right) {
        return true;
    }

    if (!array) {
        return false;
    }

    int middle = left + (right - left) / 2;
    
    MergeSort(array, left, middle, compare);
    MergeSort(array, middle+1, right, compare); 

    Merge(array, left, middle, right, compare);
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

    MergeSort(intArr,0,n-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}