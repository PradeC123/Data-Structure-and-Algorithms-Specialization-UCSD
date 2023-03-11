## Course 1: Data Structures and Algorithms Specialization - UCSD 

## Creator : Pranav Chopde 

## Date: 03-03-2023

## Alogrithmic Warm-up 

####------------------------------------------------------------------------------------------------------------------------###
# Question 1: Fibonacci Terms Calculator


# Prompt the user for input
#n = int(input())

# If n is 0 or 1, print n and exit the program


# Define a function that calculates the nth Fibonacci number
def Fibonacci_series(n):
    # If n is 0 or 1, print n and exit the program (Base Case)
    if n <= 1:
        return n
    a, b = 0, 1 # Set the initial values for the Fibonacci sequence
    for _ in range(n-1): # Loop n-1 times to generate the nth Fibonacci number
        c = a + b # Calculate the next number in the Fibonacci sequence
        b, a = c, b # Update the values of a and b for the next iteration
    return c # Print the nth Fibonacci number


####------------------------------------------------------------------------------------------------------------------------###
# Question 2: Last Digit of a Large Fibonacci Number 

def Fibonacci_LastDigit(n):
    return Fibonacci_series(n) % 10 

####------------------------------------------------------------------------------------------------------------------------###
# Question 3: Greatest Common Divisor 
'''
Input:
The program takes two integers a and b as input, for which the Greatest Common Divisor (GCD) is to be calculated.

Functionality:
The program calculates the GCD of two integers a and b using the Euclidean algorithm. The Euclidean algorithm states that the GCD of two numbers is equal to the GCD of the smaller number and the remainder when the larger number is divided by the smaller number. The program uses a while loop to repeatedly calculate the remainder when the larger number is divided by the smaller number and then updates the values of a and b to be the smaller number and the remainder respectively. The loop continues until the remainder becomes zero, at which point the GCD has been found and the program returns the value of a.

Logic:
The program defines a function GCD that takes two integer arguments a and b, for which the GCD is to be calculated. The function initializes a while loop that continues to execute as long as b is not equal to zero. In each iteration of the loop, the function calculates the remainder of a divided by b using the modulo operator, and then updates the values of a and b to be b and the remainder respectively. The loop continues until b becomes zero, at which point the value of a is returned as the GCD.

Output:
The program returns the value of the GCD of the two input integers a and b. No output message is displayed to the user.
'''
def GCD(a,b):
    while b != 0:
        a, b = b, a%b 
    return a

####------------------------------------------------------------------------------------------------------------------------###
# Question 4: Lowest Common Multiple
"""
Functionality:
The function calculates the LCM (Least Common Multiple) of two numbers a and b using the formula LCM(a,b) = (ab)/GCD(a,b), where GCD(a,b) is the Greatest Common Divisor of a and b. The function first calls the GCD function to calculate the GCD of a and b, and then returns the value of (ab)/GCD(a,b) as the LCM of a and b.

Logic:
The function first calls the GCD function to calculate the GCD of a and b. It then calculates the LCM using the formula LCM(a,b) = (a*b)/GCD(a,b) and returns the value of LCM as the result.

Output:
The function returns an integer value that represents the LCM of the two input numbers a and b.
"""
def LCM(a,b):
    return a*b/GCD(a,b)
####------------------------------------------------------------------------------------------------------------------------###
# Question 5: Last Digit of a Large Fibonacci Number

def Fibonacci_modulu(n,m):
    return Fibonacci_series(n) % m

####------------------------------------------------------------------------------------------------------------------------###
# Question 6: Last Digit of a sum of Fibonaccii Numbers 
def Fibonacci_sum(n):
    a,b = 0, 1 
    sum_fib = 1
    for _ in range(n-1):
        c = a + b 
        sum_fib += c 
        a, b = b, c 
    return sum_fib % 10 
####------------------------------------------------------------------------------------------------------------------------###
# Question 7: Last Digit of the sum of Fibonacci Numbers (Partial sum) Again 

def Fibonacci_partial_Lastdigit(m, n):
    """
    Computes the last digit of the sum of Fibonacci numbers from the mth to the nth
    (inclusive) Fibonacci number, using a loop.

    Args:
        m (int): the starting index (1-based) of the sum
        n (int): the ending index (1-based) of the sum

    Returns:
        int: the last digit of the sum of Fibonacci numbers from the mth to the nth
    """
    a, b = 0, 1  # Initialize the first two Fibonacci numbers
    sum_partial_m = 1  # Initialize the sum from the first Fibonacci number to mth Fibonacci number
    total_sum = 1  # Initialize the total sum to 1 (accounting for the first Fibonacci number)
    c = 0  # Initialize the next Fibonacci number

    # Iterate over the Fibonacci numbers from the 3rd to the nth
    for i in range(n - 1):
        c = a + b  # Compute the next Fibonacci number
        if i + 2 < m:  # If we haven't reached the mth Fibonacci number yet
            sum_partial_m += c  # Add the current Fibonacci number to the partial sum
        total_sum += c  # Add the current Fibonacci number to the total sum
        a, b = b, c  # Update the values of a and b for the next iteration
        print(c, total_sum)  # Print the current Fibonacci number and the total sum so far

    return (total_sum - sum_partial_m) % 10  # Return the last digit of the sum


####------------------------------------------------------------------------------------------------------------------------###
# Question 8: Last Digit of the sum of Fibonacci Numbers (Partial sum) Again 

def Fibonacci_square(n):
    a, b = 0, 1
    sum_fibonnaci_square = 1
    for _ in range(n-1):
        c = a + b 
        sum_fibonnaci_square += c**2
        a, b = b, c  
    print(sum_fibonnaci_square)
    return sum_fibonnaci_square % 10 

#print(Fibonacci_square(1234567890))


