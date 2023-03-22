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
// Question 2 Majority Element: 
int getMajorityElement(int[] arr, int left, int right){
    if(left == right){
        return arr[left]
    }
    int mid = left + (right - left) / 2; 
    int left_majority = getMajorityElement(arr, left, mid);
    int right_majority = getMajorityElement(arr, mid+1 , right); 

    int left_count = 0; 
    for(int i = left; i < right + 1; i++){
        if(a[i] == left_majority){
            left_count +=1; 
        }
    }
    
    int right_count = 0; 
    for(int = left; i < right + 1; i++){
        if (a[i] == right_majority){
            right_count += 1; 
        }
    }

    if(left_count > (right - left + 1) / 2 ){
        return left_majority;
    }
    else if(right_count > (right - left + 1) / 2){
        return right_majority;
    }
    else{
        return -1;
    }
} 
//----------------------------------------------------------------------
// Question 3 Improving Quick Sort: 


//----------------------------------------------------------------------
// Question 4 Number of Inversion: 

//----------------------------------------------------------------------
// Question 5 Organizing a Lottery: 

//----------------------------------------------------------------------
// Question 6 Closest Point: 


//----------------------------------------------------------------------
// Int Main: 

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