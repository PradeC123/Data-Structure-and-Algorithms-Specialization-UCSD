#include <stdio.h>
#include <stdlib.h>
///---------------------------------------------------------------------------------/
// Question 1 Binary Search 
int binarySearch(int arr[], int left, int right, int elem) {
    int mid = left + (right - left) / 2; 
    if (right >= left) {
        if (arr[mid] == elem) {
            return mid;
        } else if (arr[mid] > elem) {
            return binarySearch(arr, left, mid - 1, elem);
        } else {
            return binarySearch(arr, mid + 1, right, elem); 
        }
    } else {  
        return -1;
    }
}
///---------------------------------------------------------------------------------/
int* searchindx_arr(int arr[],int arrlen, int keys[], int keyslen){
    int* lst_index; 
    lst_index = (int*)calloc(keyslen, sizeof(int)); 
    for(int i = 0; i < keyslen; i++){
        lst_index[i] = binarySearch(arr, 0, arrlen - 1, keys[i]);
    }
    return lst_index; 
}
//----------------------------------------------------------------------
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int keys[] = {23, 8, 91, 100, 5};
    int arr_len = 10;
    int keys_len = 5;
    int* result = searchindx_arr(arr, arr_len, keys, keys_len);
    for (int i = 0; i < keys_len; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
// Runtime O(klog(n))
///---------------------------------------------------------------------------------/
// Question 2: Majority Element 