#include<stdio.h>
#include<stdlib.h>

// ----------------------------------------------------------------------------------------------------// 
// Question 1:
// Recursive implementation of the Fibonacci sequence
int fibonacci_naive(int n){
    if(n <= 1){ // Base case: if n is 0 or 1, return n
        return n;
    }
    // Recursive call to calculate the n-th Fibonacci number
    return fibonacci_naive(n-1) + fibonacci_naive(n-2); 
}

// Iterative implementation of the Fibonacci sequence
int fibonacci_fast(int n){
    int temp_var_1 = 0, temp_var_2 = 1, temp_var_fib; 
    // Loop to calculate the n-th Fibonacci number
    for(int i = 2; i <= n; i++){
        // Calculate the next Fibonacci number by adding the two previous numbers
        temp_var_fib = temp_var_1 + temp_var_2;
        // Update the values of the two previous numbers for the next iteration
        temp_var_1 = temp_var_2;
        temp_var_2 = temp_var_fib;
    }
    // Return the n-th Fibonacci number
    return temp_var_fib;
}

// ----------------------------------------------------------------------------------------------------// 
// ----------------------------------------------------------------------------------------------------// 
// Question 2: Last digit of the large Fibonacci Number
// Recursive implementation of the Fibonacci sequence

// This function takes a number 'num' as input and returns the last digit of the Fibonacci number at index 'num'
int Fibonacci_lastnum(long long num){
    // Initialize variables
    int temp_var_1 = 0, temp_var_2 = 1, last_digit;
    
    // Loop through the Fibonacci sequence until reaching the desired index
    for(int i = 2; i <= num; i++){
        // Calculate the last digit of the next number in the sequence
        last_digit = (temp_var_1 + temp_var_2) % 10;
        
        // Update the variables for the current and previous numbers in the sequence
        temp_var_1 = temp_var_2; 
        temp_var_2 = last_digit; 
    }
    
    // Return the last digit of the Fibonacci number at the desired index
    return last_digit;
}


// ----------------------------------------------------------------------------------------------------// 
// Question 3: GCD of a number 
// Recursive implementation of the GCD algorithm 

long long GCD(long long a, long long b){
    while(b != 0){
        a = b;
        b = a%b;
    }
    return b; 
}

//----------------------------------------------------------------------------------------------------// 
// Question 4: LCM of a number 
// Recursive implementation of the GCD algorithm 

long long LCM(long long a, long long b){
    return a*b/GCD(a,b);
}

//----------------------------------------------------------------------------------------------------// 
// Function to find the Pisano Period of a number
long long get_pisano_period(long long m){
    long long temp_var_1 = 0, temp_var_2 = 1, temp_var_fib;
    // Loop through a maximum of m^2 iterations to find Pisano Period
    for(int i = 0; i < m*m; i++){
        temp_var_fib = (temp_var_1 + temp_var_2) % m;
        temp_var_1 = temp_var_2;
        temp_var_2 = temp_var_fib;
        // Check if the period has restarted
        if (temp_var_1 == 0 && temp_var_2 == 1){
            return i+1;
        }
    }
}

// Function to find the nth Fibonacci number modulo m using Pisano Period
long long get_fibonacci_huge_fast(long long n, long long m){
    // Find the remainder when n is divided by the Pisano Period of m
    long long remainder = n % get_pisano_period(m); 
    long long temp_var_1 = 0;
    long long temp_var_2 = 1;
    long long temp_var_fib; 

    // Compute the Fibonacci number modulo m using remainder
    for(int i = 2; i < remainder; i++){
        temp_var_fib = (temp_var_1 + temp_var_2) % m;
        temp_var_1 = temp_var_2; 
        temp_var_2 = temp_var_fib; 
    }
    return temp_var_fib % m; 
}


//----------------------------------------------------------------------------------------------------// 
// Question 6: Function to calculate the Pisano period and the sum of Fibonacci numbers modulo m
long long get_pisano_period_sum(long long m, long long *sum){
    // Initialize the first two Fibonacci numbers
    long long temp_var_1 = 0, temp_var_2 = 1, temp_var_fib;
    // Initialize the sum of Fibonacci numbers
    *sum = temp_var_1 + temp_var_2;
    // Iterate through the sequence to find the Pisano period
    for(int i = 0; i < m*m; i++){
        // Calculate the next Fibonacci number modulo 10
        temp_var_fib = (temp_var_1 + temp_var_2) % 10;
        // Update the previous two Fibonacci numbers
        temp_var_1 = temp_var_2;
        temp_var_2 = temp_var_fib;
        // Add the current Fibonacci number to the sum modulo 10
        *sum = (*sum + temp_var_2) % 10;
        // Check if the period has ended and return the period length if true
        if (temp_var_1 == 0 && temp_var_2 == 1){
            *sum = (*sum + 9) % 10;
            return i+1;
        }
    }
}

// Function to calculate the last digit of the sum of the first n Fibonacci numbers modulo m
long long get_lastdigit_sumFib(long long n, long long m) {
    // Initialize the sum of Fibonacci numbers and the remainder after dividing n by the Pisano period
    long long sum = 0; 
    long long remainder = n % get_pisano_period_sum(m, &sum); 
    // Initialize the first two Fibonacci numbers
    long long temp_var_1 = 0;
    long long temp_var_2 = 1;
    long long temp_var_fib; 
    // Initialize the sum of the first two Fibonacci numbers
    long long temp_sum = temp_var_1 + temp_var_2; 

    // Iterate through the sequence to find the sum of the first n Fibonacci numbers modulo m
    for(int i = 2; i < remainder; i++){
        // Calculate the next Fibonacci number modulo 10
        temp_var_fib = (temp_var_1 + temp_var_2) % 10;
        // Update the previous two Fibonacci numbers
        temp_var_1 = temp_var_2; 
        temp_var_2 = temp_var_fib; 
        // Add the current Fibonacci number to the sum modulo 10
        temp_sum = (temp_sum + temp_var_2) % 10;
    }
    // Return the sum of the first n Fibonacci numbers modulo m
    return (sum + temp_sum) % m; 
}


// ----------------------------------------------------------------------------------------------------//
// Question 7: Partial sum of the Fibonacci Numbers

// This function calculates the last digit of the partial sum of Fibonacci numbers from m to n.
long long get_lastdigits_partialsum(int m, int n){
    // Get the last digit of the sum of Fibonacci numbers up to n.
    long long sum_n = get_lastdigit_sumFib(n);
    // Get the last digit of the sum of Fibonacci numbers up to m-1.
    long long sum_m = get_lastdigit_sumFib(m-1);
    // Calculate the last digit of the partial sum of Fibonacci numbers from m to n.
    return (sum_n - sum_m) % 10;
}

//----------------------------------------------------------------------------------------------------//
// Question 8: Last Digit of the Sum of Squares of the Fibonacci numbers

// This function calculates the last digit of the sum of squares of Fibonacci numbers up to n.
long long get_lastdigit_squaresum(int n){
    // Get the nth Fibonacci number modulo 10.
    long long F_n = get_fibonacci_huge_fast(n, 10);
    // Get the (n-1)th Fibonacci number modulo 10.
    long long F_n_1 = get_fibonacci_huge_fast(n-1, 10);
    // Calculate the last digit of the sum of squares of Fibonacci numbers up to n.
    return (F_n*F_n_1) % 10;
}