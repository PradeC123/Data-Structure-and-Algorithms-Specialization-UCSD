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
// Question 2: Last digit of the large Fibonacci Number
// Recursive implementation of the Fibonacci sequence

int Fibonacci_lastnum(long long num){
    int temp_var_1 = 0, temp_var_2 = 1, last_digit;
    for(int i = 2; i <= n; i++){
        last_digit = (temp_var_1 + temp_var_2) % 10;
        temp_var_1 = temp_var_2; 
        temp_var_2 = last_digit; 
    }
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
// Question 5: Fibonacci Number again 
long long get_pisano_period(long long m){
    long long temp_var_1 = 0, temp_var_2 = 1, temp_var_fib;
    for(int i = 0; i < m*m; i++){
        temp_var_fib = (temp_var_1 + temp_var_2) % 10;
        temp_var_1 = temp_var_2;
        temp_var_2 = temp_var_fib;
        if (temp_var_1 == 0 && temp_var_2 == 1){
            return i+1;
        }
    }
}

long long get_fibonacci_huge_fast(long long n, long long m){
    long long remainder = n % get_pisano_period(m); 
    long long temp_var_1 = 0;
    long long temp_var_2 = 1;
    long long temp_var_fib; 

    for(int i = 2; i < remainder; i++){
        temp_var_fib = (temp_var_1 + temp_var_2) % 10;
        temp_var_1 = temp_var_2; 
        temp_var_2 = temp_var_fib; 
    }
    return temp_var_fib % m; 
}

//----------------------------------------------------------------------------------------------------// 
// Question 6: Last Digit of the Sum of Fibonacci Numbers 
