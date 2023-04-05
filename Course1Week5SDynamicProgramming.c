#include<stdio.h>
#include<stdlib.h>

// Int function
int min(int elem1, int elem2){
    return (elem1 > elem2) ? elem2 : elem1;
}

int max(int elem1, int elem2){
    return (elem1 > elem2) ? elem1 : elem2;
}

int min3(int elem1, int elem2, int elem3){
    return min(elem1,min(elem2,elem3));
}
int max3(int elem1, int elem2, int elem3) {
    return max(elem1,max(elem2,elem3));
}
//-------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------
// Question 4: 
int lcs2D(int seq1[], int len_seq1, int seq2[], int len_seq2){
    int dp[len_seq1+1][len_seq2+1];
    // Initialization of the DP array.
    for(int i = 0; i < len_seq1+1; i++){
        for(int j = 0; j < len_seq2+1; j++){
            dp[i][j] = 0;
        }
    }
    // Filling up the DP array. 
    for(int i = 1; i < len_seq1 + 1; i++){
        for(int j = 1; j < len_seq2 + 1; j++){
            if(seq1[i] == seq2[j]){
                dp[i][j] =  1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[len_seq1][len_seq2];
}
//-------------------------------------------------------------------------------------------------
// Question 5: 
int lcs3(int a[], int n, int b[], int m, int c[], int l) {
    int dp[n+1][m+1][l+1];
    int i, j, k;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            for (k = 0; k <= l; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            for (k = 1; k <= l; k++) {
                if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max3(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[n][m][l];
}
//-------------------------------------------------------------------------------------------------
// Test cases for the algorithm
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