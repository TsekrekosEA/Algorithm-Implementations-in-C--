#include <iostream>
#include <functional>
#include <utility>


/**
 * @brief Generic InsertionSort implementation with Templates
 * 
 * @tparam T Type of elements to be sorted
 * @param array Array to be sorted
 * @param size Number of elements in the array
 * @param compare Custom comparison function (defaults to greater than)
 * @return true if the array was sorted, false if not sorted
 */
template <typename T>
bool InsertionSort(T array[], int size, std::function<bool(const T&, const T&)> compare = std::greater<T>()){

    // Error handling
    if (!array || size <= 0) {
        return false;
    }
        
    // Already sorted
    if (size == 1) {
        return true;
    }

    for (int i=1;i<size;i++){
        T current=array[i];
        int j;
        for (j=i-1;j>=0;j--){
            if(compare(current,array[j])){
                break;
            }
            array[j+1]=array[j];

        }
        array[j+1]=current;
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

    InsertionSort(intArr,n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}