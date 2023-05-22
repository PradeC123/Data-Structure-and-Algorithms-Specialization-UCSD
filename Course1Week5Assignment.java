public class Course1Week5Assignment{
    //Question 1:
    public static int min(int a, int b){
        if(a>=b){
            return b;
        }
        return a; 
    }
    public static int min3(int a,int b, int c){
        return min(a,min(b,c));
    }
    public static int coinchange(int[] coin_denom, int target){
        //Defining the DP array 
        int[] dp = new int[target+1];
        //Initialising the DP array 
        for(int i = 0; i < target +1; i++){
            dp[i] = target + 1; 
        }
        dp[0] = 0;  
        for(int i = 1; i < target + 1; i++){
            for(int j = 0; j < coin_denom.length; j++){
                if(i>=coin_denom[j]){
                    dp[i] = min(dp[i], 1+ dp[i-coin_denom[j]]); 
                }
            }
        }
        return dp[target]; 
    }
    //Question 2: 
    public static int[] primativeCal(int num){
        //Filling the name
        int[] dp = new int[num+1];
        int[] prev_num = new int [num+3];
        //Filling in the numbers
        for(int i = 0; i < num+1;i++){
            dp[i] = num;
            prev_num[i] = 0; 
        }
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < num+1; i++){
            dp[i] = min(dp[i], 1+dp[i-1]); //Number subtraction from the 1
            prev_num[i] = i-1; 
            if(i%2==0){
                dp[i] = min(dp[i], 1+dp[i/2]);
                prev_num[i] = i/2; 
            }
            if(i%3==0){
                dp[i] = min(dp[i], 1+dp[i/3]);
                prev_num[i] = i/3; 
            }
        }
        prev_num[num+1] = num;
        prev_num[num+2] = dp[num];
        return prev_num; 
    }

    // Question 3: Alignment Game
    public static int editGame(String char1, String char2){
        // Initialising the DP array
        int[][] dp = new int[char1.length()+1][char2.length()+1]; 
        for(int i = 0; i < char1.length()+1; i++){
            for(int j = 0; i < char2.length()+1; j++){
                dp[i][j] = 0; 
                if(i == char1.length()){
                    dp[char2.length()][j] = char1.length() - j;
                }
                if(j==char2.length()){
                    dp[i][char1.length()] = char2.length() - i; 
                }
            }
        }
        // Filling in the DP Matrix
        for(int i = char1.length()-1; i >=0; i--){
            for(int j = char2.length()-1; j>=0; j--){
                if(char1.charAt(i)==char2.charAt(j)){
                    dp[i][j] = min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                }else{
                    dp[i][j]= 1 + min3(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        return dp[0][0];
    }
    //Question 4: Longest Common Sequence
    public static int longCommonseq(int[] arr1, int[] arr2){
        int[][] dp = new int[arr1.length+1][arr2.length+1];
    }
    public static void main(String[] args){
        //int[] coin_denom = {1,3,4};
        ///System.out.println(coinchange(coin_denom, 10));
        int[] prev = primativeCal(12); 
        for(int i = 2; i < prev.length-1; i++){
            System.out.println(prev[i] + " ");
        }
    }
}