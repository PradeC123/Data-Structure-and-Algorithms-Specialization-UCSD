#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    while (capacity != 0){ 
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
        for(int i = indMaxweight ; i < n-1; i++){
            weights[i] = weights[i+1];
            values[i] = values[i+1];
            cost_per_weight[i] = cost_per_weight[i+1];
        }
        n--;
    }
    return value;
}
//---------------------------------------------------------------------------- 
// Question 3: Maximum Loot Price 

int car_fueling(int d, int m, int stop_arr[], int len){
    int stop_cnt = 0;
    int stop_fueling = 0; 
    stop_arr[len] = d;
    for(int i = 0; i < len; i++){
        if (stop_arr[i] + m < stop_arr[i+1]){
            return -1;
        }
         if ((stop_arr[i] <= m + stop_fueling) && (stop_arr[i+1] >= m + stop_fueling)) {
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
int cmpfunc(const void *a, const void *b) {
    return (*(int*) a - *(int*) b);
}

long long max_ad_revenue(int *a_arr, int *c_arr, int n) {
    qsort(a_arr, n, sizeof(int), cmpfunc);
    qsort(c_arr, n, sizeof(int), cmpfunc);
    long long sum_rev = 0;
    for (int i = 0; i < n; i++) {
        sum_rev += (long long) a_arr[i] * c_arr[i];
    }
    return sum_rev;
}
///------------------------------------------------------------------------### 
/// Question 5 : Maximum Number of Prizes 

///------------------------------------------------------------------------### 
/// Question 6 : Maximum Number of Prizes 
int* max_price(int n){
    int sum = 1;
    int cntr = 1; 
    int* lst = calloc(cntr, sizeof(int));
    while (n >= sum){
        lst[cntr - 1] = cntr;
        cntr += 1;
        sum += cntr;
        if (cntr > 1) {
            lst = realloc(lst, cntr * sizeof(int));  // resize lst if necessary
        }
    }
    sum -= cntr;
    lst[cntr - 2] += n - sum;
    return lst;
}

/*
int main() {
    int* result = max_price(15);
    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    free(result); // don't forget to free the dynamically allocated memory
    return 0;
}
*/

///------------------------------------------------------------------------### 
/// Question 7 : Maximum Salary  
int last_num(int n){
    int digit = 0;
    while(n!=0){
        digit = n%10; // get the last digit of the number
        n = n / 10; // remove the last digit of the number 
    }
    return digit; // return the last number of the digit
}

int IsgreaterEqual(int digit, int maxdigit){
    if (maxdigit == -1){
        return 1; // if maxdigit is -1 
    }
    return last_num(digit) >= last_num(maxdigit);
}

char* largest_number(int* digit_arr, int len) {
    char* largest_str = (char*) malloc((len + 1) * sizeof(char));
    largest_str[0] = '\0';
    int max_digit, max_index;
    while (len > 0) {
        max_digit = digit_arr[0];
        max_index = 0;
        for (int i = 1; i < len; i++) {
            if (IsgreaterEqual(digit_arr[i], max_digit)) {
                max_digit = digit_arr[i];
                max_index = i;
            }
        }
        char max_digit_str[11];
        sprintf(max_digit_str, "%d", max_digit);
        strcat(largest_str, max_digit_str);
        digit_arr[max_index] = digit_arr[len - 1];
        len--;
    }
    return largest_str;
}



