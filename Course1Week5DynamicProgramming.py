## Question 1: Money Change Again. 
##------------------------------------------------------------
def moneychangeDP(coin_arr,W):
    dp_arr = [W+1]*(W+1)
    dp_arr[0] = 0
    for i in range(1,W+1):
        for j in range(len(coin_arr)):
            if(i-coin_arr[j]>=0):
                dp_arr[i] = min(dp_arr[i], 1+dp_arr[i-coin_arr[j]])
    return dp_arr[W]

##------------------------------------------------------------
## Question 2: Primitive Calculator
def minoperCal(n):
    dp_arr = [n+1]*(n+1)
    dp_arr[0] = 0 
    dp_arr[1] = 0
    prev_branch = [0]*(n+1)
    for i in range(2,n+1):
        if (i-1)>=0: #Addition case
            dp_arr[i] = min(dp_arr[i], 1+dp_arr[i-1])
            prev_branch[i] = i-1
        if (i%2 == 0):
            dp_arr[i] = min(dp_arr[i],1+dp_arr[i//2])
            prev_branch[i] = i//2
        if (i%3 == 0):
            dp_arr[i] = min(dp_arr[i], 1 + dp_arr[i//3])
            prev_branch[i] = i//3
    operations = []
    while n>1:
        operations.append(n)
        n = prev_branch[n]
    operations.append(1)
    operations.reverse()
    return dp_arr[-1], operations

##------------------------------------------------------------
## Question 3: Alignment game


##------------------------------------------------------------
## Question 4: Longest Common Subsequence of Two Sequences
def longestcommonSeq(seq1,seq2):
    n = len(seq1)
    m = len(seq2)
    dp = [[0 for j in range(m+1)] for i in range(n+1)]
    print(dp)
    for i in range(1,n+1):
        for j in range(1,m+1):
            if seq1[i-1] == seq2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])
    return dp[n][m]
##-----------------------------------------------------------------
# Test Cases. Question 1, 2 and 4
#coin_arr = [1,3,4]
#W = 7
#print("Min coin change", moneychangeDP(coin_arr,W))
#print(minoperCal(1000))
seq1 = [1, 2, 3, 4, 5]
seq2 = [2, 4, 5, 6]
result = longestcommonSeq(seq1, seq2)
print(result) # Output: 3
