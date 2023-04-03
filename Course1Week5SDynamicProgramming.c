#include<stdio.h>
#include<stdlib.h>

// Int function
int min(int elem1, int elem2){
    return (elem1 > elem2) ? elem2 : elem1;
}

int min3(int elem1, int elem2, int elem3){
    return min(elem1,min(elem2,elem3));
}

// Question 1: Money Change
int coinchangeDP(int coin_denom[], int len_coin, int target){
    // Initialization and the base case of the DP array 
    int dp[target+1]; 
    for(int i = 0; i < target+1; i++){
        dp[i] = target+1; 
    }
    dp[0] = 0;
    // Filling in the DP array 
    for(int i = 0; i < len_coin; i++){
        for(int j = 1; j < target + 1; j++){
            if(j>=coin_denom[i]){
                dp[j] = min(dp[j], 1 + dp[j-coin_denom[i]]);
            }
        }
    }
    return dp[target];
}

// Question 2: Primitive Calculator
int mincalcDP(int num){
    // Initialization of the DP matrix
    int dp[num+1];
    for(int i = 0; i < num+1; i++){
        dp[i] = num+1; 
    }
    dp[0] = 0;
    dp[1] = 1;
    //Filling in the DP matrix
    for(int i = 2; i < num+1; i++){
        dp[i] = min(dp[i],1 + dp[i-1]); 
        if(i%2 == 0){
            dp[i] = min(dp[i],1 + dp[i/2]);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i],1 + dp[i/3]);
        }
    }
    return dp[num];
}
// Question 3: Alignment Game
int editDistance(char seq1[], int seq1n, char seq2[], int seq2n){
    //Initialization of the DP
    int dp[seq1n+1][seq2n+1];
    for(int i = 0; i < seq1n+1; i++){
        for(int j = 0; j < seq2n+1; j++){
            dp[i][j] = 0;
            if(i == seq1n){
                dp[seq1n][j] = seq1n - j; 
            }
            if(j == seq2n){
                dp[i][seq2n] = seq2n - i; 
            }
        }
    }
    // Filling in the DP array
    for(int i = seq1n-1; i >= 0; i--){
        for(int j = seq2n-1; j>=0; j--){
            if(seq1[i] == seq2[j]){
                dp[i][j] = min3(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]); 
            }
            else{
                dp[i][j] = 1 + min3(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    /*
    int coins[] = {1, 5, 10, 25};
    int len_coin = 4;
    int target = 63;
    int result = coinchangeDP(coins, len_coin, target);
    printf("Minimum number of coins required: %d\n", result);
    */
    int num = 10;
    int result = mincalcDP(num);
    printf("Minimum number of operations required: %d\n", result);
    // Question 3: Test cases
    char seq1[] = "shorts";
    char seq2[] = "ports";
    int seq1n = 6;
    int seq2n = 7;
    int result_1 = editDistance(seq1, seq1n, seq2, seq2n);
    printf("editDistance(%s, %s) = %d\n", seq1, seq2, result_1);
    return 0;
}