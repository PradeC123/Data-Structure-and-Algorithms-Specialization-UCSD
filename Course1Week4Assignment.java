import java.util.Arrays;

public class Course1Week4Assignment{
    public static int binarySearch(int arr[], int left, int right, int elem){
        int mid; 
        mid = left + (right - left) / 2;
        if(right>=left){
            if(arr[mid] == elem){
                return mid; 
            }
            else if (arr[mid] > elem){
                return binarySearch(arr, left, mid - 1, elem);
            }
            else{
                return binarySearch(arr, mid + 1, right, elem);
            }
        }
        else{
            return -1;
        }
    }
    public static int[] searchindx_arr(int[] arr,int[] keys){
        int[] lst_index = new int[keys.length]; 
        for(int i = 0; i < keys.length; i++){
            lst_index[i] = binarySearch(arr, 0, arr.length - 1, keys[i]);
        }
        return lst_index;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6};
        int[] keys = {1, 3, 6, 7};
        int[] expected = {0, 2, 5, -1};
        int[] actual = searchindx_arr(arr, keys);
    
        System.out.println(Arrays.equals(expected, actual)); // true
    }
    
} 