#include<stdio.h>
#include<stdlib.h>

//---------------------------------------------------------------------------- 
// Question 1 : Money Change 
int coinchange(int n) {
    int coin_change[3] = {1, 5, 10};
    int count_coin = 0;
    while (n != 0) {
        if (n >= coin_change[2]) {
            count_coin++;
            n -= coin_change[2];
        } else if (n >= coin_change[1]) {
            count_coin++;
            n -= coin_change[1];
        } else {
            coin_change[2] = 0;
            coin_change[1] = 0;
            count_coin++;
            n -= coin_change[0];
        }
    }
    return count_coin;
}
//---------------------------------------------------------------------------- 
// Question 2: Maximum Loot Price 

double optimal_value_loot(int capacity, int weights[], int values[], int n){
    double value = 0;
    double cost_per_weight[n];

    //Calculate cost per weight for each item
    for(int i = 0; i < n; i++){
        cost_per_weight[i] = values[i] / weights[i];
    }
    while(capacity! = 0){
        //Find the item with the highest cost per weight 
        int indMaxweight = 0;
        for(int i = 1; i < n; i++){
            if(cost_per_weight[i] > cost_per_weight[indMaxweight]){
                indMaxweight = i;
            }
        }
        // Determine the amount to take from the item
        int min_cap;
        if (weights[indMaxweight] < capacity){
            min_cap = weights[indMaxweight];
        }
        else{
            min_cap = capacity;
        }
        // Update Capacity and value 
        capacity -= min_cap;
        value += min_cap * cost_per_weight[indMaxweight];

        // Remove the item with the highest cost per weight 
        for(int i = indMaxweightl i < n-1; i++){
            weights[i] = weights[i+1];
            values[i] = values[i+1];
            cost_per_weight[i] = cost_per_weight[i+1];
        }
        n--;

    }
}
//---------------------------------------------------------------------------- 
// Question 3: Maximum Loot Price 

int car_fueling(int d, int m, int stop_arr[], int len){
    int stop_cnt = 0;
    int stop_fueling = 0; 
    stop_arr[len] = d;
    for(int i = 0; i < len; i++){
        if (stop_arr[i] + m < stop_arr[i+1]){
            return -1
        }
         if ((stop_arr[i] < m + stop_fueling) && (stop_arr[i+1] > m + stop_fueling)) {
            stop_fueling = stop_arr[i];
            stop_cnt += 1;
        }
        if (stop_cnt == 0 && i == len - 1) {
            return 0;
        }
    }
    return stop_cnt;
}

///------------------------------------------------------------------------### 
/// Question 4 : Maximum Advertisement Revenue
