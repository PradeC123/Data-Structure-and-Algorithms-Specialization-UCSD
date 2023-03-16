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
    // Question 2 : Maximum Value of the Loot (Greedy Implementation )
    public static double optimaloot(int capacity, double[] weights, double[] values){
        double value_loot = 0.0;
        double[] cost_per_weight = new double[weights.length]; //Initialization of the cost per weight array 
        boolean[] isVisited = new boolean[weights.length];

        // Assigning the values of the cost per weight in the array
        // Assigning the values of the isVisited to False intially => When the nodes are visited then we assign the value to true and then never visit the node again
        for(int i = 0; i < weights.length; i++){
            cost_per_weight[i] = values[i] / weights[i];
            isVisited[i] = false; 
        }
        // Calculating the value of the loot by iterating over the weights, values and the cost_per_weight
        while(capacity !=0){
            double MaxWeight = 0.0;
            int indMaxWeight = -1;
            // Finding the maximum value of cost per weight. 
            for(int i = 0; i < cost_per_weight.length ; i++){
                if((!isVisited[i]) && (cost_per_weight[i] > MaxWeight)){
                    MaxWeight = cost_per_weight[i];
                    indMaxWeight = i;
                }
            }
            double min_cap = Math.min(capacity,weights[indMaxWeight]);
            capacity -= min_cap; 
            value_loot += min_cap * cost_per_weight[indMaxWeight]; 
            isVisited[indMaxWeight] = true;
        }
        return Math.round(value_loot * 10000.0) / 10000.0;        
    }

    //--------------------------TESTING THE CODE------------------------ 
    public static void main(String[] args) {
    System.out.println("Test Cases for Question 1:\n");
    // ---------------- Question 1---Test Case 1------------------------
    int n1 = 13;
    int expected1 = 4;
    int result1 = coinchange(n1);
    System.out.println("Test case 1 - Expected output: " + expected1 + ", Output: " + result1);
    
    // Test case 2: Input is already a multiple of the highest coin value
    int n2 = 50;
    int expected2 = 5;
    int result2 = coinchange(n2);
    System.out.println("Test case 2 - Expected output: " + expected2 + ", Output: " + result2);
    
    // Test case 3: Input is a multiple of a coin value other than the highest
    int n3 = 25;
    int expected3 = 3;
    int result3 = coinchange(n3);
    System.out.println("Test case 3 - Expected output: " + expected3 + ", Output: " + result3);
    
    // Test case 4: Input is less than the value of the smallest coin
    int n4 = 1;
    int expected4 = 1;
    int result4 = coinchange(n4);
    System.out.println("Test case 4 - Expected output: " + expected4 + ", Output: " + result4);
    
    // Test case 5: Input is equal to the value of the smallest coin
    int n5 = 1;
    int expected5 = 1;
    int result5 = coinchange(n5);
    System.out.println("Test case 5 - Expected output: " + expected5 + ", Output: " + result5);
    
    // Test case 6: Input is negative
    int n6 = -10;
    int expected6 = 0;
    int result6 = coinchange(n6);
    System.out.println("Test case 6 - Expected output: " + expected6 + ", Output: " + result6);
    System.out.println("\n");
    System.out.println("Test Cases for Question 2:\n");

    // ---------------- Question 2-----Test Case 2-------------------
    // Test case 1: Basic test case with small inputs// Test case 1: Basic test case with small inputs
    // Test case 1: Example from the prompt
    // Test case 1: Example from the prompt
    int capacity1 = 50;
    double[] weights1 = {10, 20, 30};
    double[] values1 = {60, 100, 120};
    double expected_1 = 240.0000;

    // Test case 2: Capacity is less than the weight of all items
    int capacity2 = 15;
    double[] weights2 = {20, 30, 40};
    double[] values2 = {100, 120, 140};
    double expected_2 = 75.00;

    // Test case 3: All items have the same cost per weight
    int capacity3 = 40;
    double[] weights3 = {10, 20, 30};
    double[] values3 = {50, 100, 150};
    double expected_3 = 200.0000;

    // Test case 4: All items have the same weight but different values
    int capacity4 = 100;
    double[] weights4 = {50, 50, 50};
    double[] values4 = {20, 30, 40};
    double expected_4 = 70.0000;

    // Test case 5: Capacity is greater than the total weight of all items
    int capacity5 = 200;
    double[] weights5 = {50, 100, 150};
    double[] values5 = {60, 100, 120};
    double expected_5 = 200.0000;

    // Test case 6: One item has zero weight and value
    int capacity6 = 50;
    double[] weights6 = {0, 20, 30};
    double[] values6 = {0, 100, 120};
    double expected_6 = 220.0000;

    // Test case 7: Only one item is available and its weight is greater than the capacity
    int capacity7 = 5;
    double[] weights7 = {10};
    double[] values7 = {50};
    double expected_7 = 25.00;

    // Run the tests and print the results
    double result_1 = optimaloot(capacity1, weights1, values1);
    double result_2 = optimaloot(capacity2, weights2, values2);
    double result_3 = optimaloot(capacity3, weights3, values3);
    double result_4 = optimaloot(capacity4, weights4, values4);
    double result_5 = optimaloot(capacity5, weights5, values5);
    double result_6 = optimaloot(capacity6, weights6, values6);
    double result_7 = optimaloot(capacity7, weights7, values7);

    System.out.println("Test case 1: Expected = " + expected_1 + ", Result = " + result_1);
    System.out.println("Test case 2: Expected = " + expected_2 + ", Result = " + result_2);
    System.out.println("Test case 3: Expected = " + expected_3 + ", Result = " + result_3);
    System.out.println("Test case 4: Expected = " + expected_4 + ", Result = " + result_4);
    System.out.println("Test case 5: Expected = " + expected_5 + ", Result = " + result_5);
    System.out.println("Test case 6: Expected = " + expected_6 + ", Result = " + result_6);
    System.out.println("Test case 7: Expected = " + expected_7 + ", Result = " + result_7);

    }
}
