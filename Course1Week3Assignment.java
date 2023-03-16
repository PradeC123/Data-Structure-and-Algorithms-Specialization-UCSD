import java.lang.reflect.Array;

public class Course1Week3Assignment {
    //-------------------------------------------------------------------------//
    // Question 1 : Money Change 

    // Finding the maximum element in an array
    public static int[] findMax(int[] arr){
        int max = arr[0];
        int index = 0;
        for(int i = 0; i < arr.length; i++){
            if (arr[i] > max){
                max = arr[i];
                index = i;
            }
        }
        return new int[]{max,index};
    }
    // Removing the element from an array
    public static int[] removeElement(int[] arr, int index){
        int[] newArr = new int[arr.length -1];
        for(int i = 0, j = 0; i < arr.length ; i++){
            if (i != index){
                newArr[j] = arr[i];
                j++;
            }
        }
        return newArr;
    }
    // Findthe the coinchange need to implement. 
    public static int coinchange(int n) {
        int[] coin_change = {1,5,10};
        int count_coin = 0; 
        while(n >= 0 && coin_change.length > 0){
            int max_coin = findMax(coin_change)[0];
            int max_index = findMax(coin_change)[1];
            if (n >= max_coin){
                count_coin += 1;
                n -= max_coin;
            }
            else{
                coin_change = removeElement(coin_change, max_index);
            }
        }
        return count_coin;         
    }
    //-------------------------------------------------------------------------//
    // Question 2 : Maximum Value of the Loot


    //--------------TESTING THE CODE------------
    public static void main(String[] args) {
        System.out.println(coinchange(19));
    }

}
