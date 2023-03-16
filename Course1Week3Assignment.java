import java.lang.reflect.Array;
import java.util.Arrays;

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
    /* 
    def car_fueling(d,m,stop_arr):
    stop_cnt = 0      # initialize the number of stops made to 0
    stop_fueling = 0  # initialize the distance of the last fuel stop to 0
    stop_arr.append(d)  # append the destination to the list of stops
    for i in range(0,len(stop_arr)-1):  # iterate over the list of stops
        if stop_arr[i] + m < stop_arr[i+1]:  # if the car can't reach the next stop without refueling
            return -1  # return -1 indicating it's impossible to reach the destination
        if (stop_arr[i] < m + stop_fueling) and (stop_arr[i+1] > m + stop_fueling):  # if the car needs to refuel at the current stop
            stop_fueling = stop_arr[i]  # set the distance of the last fuel stop to the current stop
            stop_cnt += 1  # increment the number of stops made
        if stop_cnt == 0 and i == len(stop_arr) - 1:  # if no stops were made and the destination has been reached
            return 0  # return 0 indicating no stops were needed
    return stop_cnt  # return the number of stops made*/

    //-------------------------------------------------------------------------//
    // Question 3 : Maximum Value of the Loot (Greedy Implementation )
    public static int car_fueling(int d, int m, int[] stop_arr){
        int stop_cnt = 0;
        int stop_fueling = 0;
        int[] stops = Arrays.copyOf(stop_arr, stop_arr.length + 1);
        stops[stops.length - 1] = d;
        //stop_arr[stop_arr.length - 1] = d; 
        for(int i = 0; i < stops.length-1; i++){
            if (stops[i] + m < stops[i+1]){
                return -1;
            }
            if ((stops[i] <= m + stop_fueling) && (stops[i+1] >= m + stop_fueling)){
                stop_fueling = stop_arr[i];
                stop_cnt += 1;
            }
            if ((stop_cnt == 0) && (i == stops.length - 2)){
                return 0;
            }
        }
        return stop_cnt;
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

    // ---------------- Question 3-----Test Case 3-------------------
    System.out.println("Test Cases for Question 3:\n");
     // Test case 1
     int d1 = 950;
     int m1 = 400;
     int[] stops1 = {200, 375, 550, 750};
     int expected_31 = 2;
     int result_31 = car_fueling(d1, m1, stops1);
     System.out.println("Test case 1 - Expected Result: " + expected_31 + ", Actual Result: " + result_31);
 
     // Test case 2
     int d2 = 10;
     int m2 = 3;
     int[] stops2 = {1,2,4,6,8};
     int expected_32 = 4;
     int result_32 = car_fueling(d2, m2, stops2);
     System.out.println("Test case 2 - Expected Result: " + expected_32 + ", Actual Result: " + result_32);
 
     // Test case 3
     int d3 = 500;
     int m3 = 100;
     int[] stops3 = {100, 200, 300, 400};
     int expected_33 = 4;
     int result_33 = car_fueling(d3, m3, stops3);
     System.out.println("Test case 3 - Expected Result: " + expected_33 + ", Actual Result: " + result_33);
 
     // Test case 4
     int d4 = 550;
     int m4 = 100;
     int[] stops4 = {100, 200, 300, 400};
     int expected_34 = -1;
     int result_34 = car_fueling(d4, m4, stops4);
     System.out.println("Test case 4 - Expected Result: " + expected_34 + ", Actual Result: " + result_34);
 
     // Test case 5
     int d5 = 500;
     int m5 = 200;
     int[] stops5 = {50, 200, 350};
     int expected_35 = 3;
     int result_35 = car_fueling(d5, m5, stops5);
     System.out.println("Test case 5 - Expected Result: " + expected_35 + ", Actual Result: " + result_35);

    }
}
