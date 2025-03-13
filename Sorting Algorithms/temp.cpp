#include <iostream>


bool SelectionSort(int arr[], int size){

    int min;
    int temp;
    int index;
    for(int i=0; i< size-1; i++){
        min=arr[i];
        index=i;
        for(int j=i+1; j<size; j++){
            if(min>arr[j]){
                index=j;
                min=arr[j];
            }
        }
        temp=arr[i];
        arr[i]=min;
        arr[index]=temp;
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