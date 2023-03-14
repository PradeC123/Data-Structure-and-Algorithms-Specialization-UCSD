import java.util.Random;

//------------------------------------------------------------------------//
// Question 1: Fast Fibonacci 
public class Course1Week2Assignment {
 /**
     * Calculates the n-th Fibonacci number using a fast algorithm.
     *
     * @param n the index of the Fibonacci number to be calculated
     * @return the n-th Fibonacci number
     */
    public static int Fibonacci_series_fast(int n) {
        // The first two Fibonacci numbers are 0 and 1
        if (n <= 1) {
            return n;
        }
        
        // Initialize variables for the previous two Fibonacci numbers and their sum
        int temp_a = 0; 
        int temp_b = 1; 
        int sum_var = 1; 
        
        // Calculate the n-th Fibonacci number by adding the previous two numbers
        for (int i = 2; i <= n; i++) {
            sum_var = temp_a + temp_b;
            temp_a = temp_b;
            temp_b = sum_var;
        }
        return sum_var;
    }
    // Slow fibonacci computation
    public static int Fibonacci_series(int n) {
        if (n <=  1) {
            return n;
        } else {
            return Fibonacci_series(n-1) + Fibonacci_series(n-2);
        }
    }
    //---------------------Stress testing----------------------//
    public static void main(String[] args) {
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            int n = random.nextInt(50) + 1;
            int fastResult = Fibonacci_series_fast(n);
            int slowResult = Fibonacci_series(n);
            if (fastResult != slowResult) {
                System.out.println("Error: Fibonacci(" + n + ") = " + slowResult + ", but got " + fastResult);
            }
        }
        System.out.println("Stress test completed!");
    }
}
//------------------------------------------------------------------------//



