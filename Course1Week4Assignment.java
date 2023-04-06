import java.util.Arrays;

public class Course1Week4Assignment{
    // Question 1: Binary Search Index
    // The function returns the index of the elem if present in the array else it returns -1
    public static int binarySearchIndex(int[] arr, int elem){  
        int left = 0;
        int right = arr.length - 1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(arr[mid] == elem){
                return mid;
            }else if(arr[mid] > elem){
                right = mid-1; 
            }
            else{
                left = mid + 1; 
            }
        }
        return -1; 
    }
    public static int[] binarySearcharray(int[] arr, int[] keys){
        int[] arr_keys = new int[arr.length];
        for(int i = 0; i < arr.length; i++){
            arr_keys[i] = binarySearchIndex(arr, keys[i]); 
        }
        return arr_keys; 
    }
    // Question 2: Majority Element:
    public static int ismajorityElem(int[] arr, int left, int right){
        if(left == right){
            return arr[left];
        }
        int mid = left + (right - left)/2; 
        int left_majority = ismajorityElem(arr, left, mid);
        int right_majority = ismajorityElem(arr, mid + 1, right); 

        if(left_majority == right_majority){
            return left_majority;
        }

        int left_count = 0;
        for(int i = left; i < right +1; i++){
            if (arr[i] == left_majority){
                left_count +=1;
            }
        }

        int right_count = 0; 
        for(int i = left; i < right + 1; i++){
            if(arr[i] == right_majority){
                right_majority +=1;
            }            
        }
        if(left_count > (right - left + 1)/2){
            return left_majority; 
        }else if(right_count > (right - left +1)/2){
            return right_majority;
        }else{
            return -1; 
        }
    }
    //--------------------------------------------------------------------------------------------
    // Question 3:

    //--------------------------------------------------------------------------------------------
    // Question 4: Nummber of Inversions
    public static int[] mergeSort(int[] arr, int left, int right){
        if(left == right){
            int[] arr_new = {arr[left]};
            return arr_new;
        }
        int mid = left + (right -left)/2;
        int[] left_arr = new int[mid];
        int[] right_arr = new int[right - mid]; 

        //Filling in the left array 
        for(int i = 0; i < mid; i++){
            left_arr[i] = arr[i];
        }
        //Filling in the right array
        for(int i = mid; i < right; i++){
            right_arr[i-mid] = arr[i];
        }
        mergeSort(left_arr, left, mid-1);
        mergeSort(right_arr, mid, right); 
        int[] merged_arr = new int[left_arr.length + right_arr.length];
        int i = 0, j = 0, k = 0; 
        while(i < left_arr.length && j < right_arr.length){
            if(left_arr[i]<=right_arr[j]){
                merged_arr[k] = left_arr[i];
                i++;
            }else{
                merged_arr[k] = right_arr[j];
                j++;
            }
            k++;
        }
        while(i < left_arr.length){
            merged_arr[k] = left_arr[i];
            i++;
            k++;
        }
        while(j < right_arr.length){
            merged_arr[k] = right_arr[j];
            j++;
            k++;
        }
        return merged_arr;
    }
    //--------------------------------------------------------------------------------------------
    // Question 4: 

    //--------------------------------------------------------------------------------------------
    // Question 5: 
    public static int cntlottery(int[][] arr, int elem) {
        if (arr.length <= 1) {
            if (arr[0][0] <= elem && arr[0][1] >= elem) {
                return 1;
            }
            return 0;
        }
        int mid = arr.length / 2;
    
        int[][] left_arr = Arrays.copyOfRange(arr, 0, mid);
        int[][] right_arr = Arrays.copyOfRange(arr, mid, arr.length);
    
        int left_cntlottery = cntlottery(left_arr, elem);
        int right_cntlottery = cntlottery(right_arr, elem);
    
        return left_cntlottery + right_cntlottery;
    }
    //     


    public static void main(String[] args){
        int[] arr = {1,2,5,6,11,12};
        int[] keys = {1,4,8,9,2,11,12};
        int[] key_index = binarySearcharray(arr, keys);
        for(int i = 0; i < key_index.length; i++){
            System.out.println(key_index[i]+"\n");
        }
        int[] arr_key = {2,2,2,2,5,5,6};
        System.out.println(ismajorityElem(arr_key, 0, arr_key.length-1));
        int[] arr3 = {4, 6, 2, 8, 3, 1, 5, 7};
        int[] sortedArr3 = mergeSort(arr3, 0, arr3.length-1);
        System.out.println(Arrays.toString(sortedArr3)); // should output [1, 2, 3, 4, 5, 6, 7, 8]     
    } 
}
