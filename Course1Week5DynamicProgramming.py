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
def editdistanace(seq1,seq2):
    n = len(seq1)
    m = len(seq2)
    dp = [[0 for j in range(n+1)] for i in range(m+1)]
    ## Assigning the base cases for the array 
    for i in range(n+1):
        dp[m][i] = len(seq1) - i
    for j in range(m+1):
        dp[j][n] = len(seq2) - j
    ## Filling in the elements in the arrays
    for i in range(n-1,-1,-1):
        for j in range(m-1,-1,-1):
            if seq1[i] == seq2[j]:
                 dp[j][i] = min(dp[j+1][i],dp[j+1][i+1],dp[j][i+1])
            else:
                dp[j][i] = 1 + min(dp[j+1][i],dp[j+1][i+1],dp[j][i+1])
    return dp[0][0]
##------------------------------------------------------------
## Question 4: Longest Common Subsequence of Two Sequences
def longestcommonSeq(seq1,seq2):
    n = len(seq1)
    m = len(seq2)
    dp = [[0 for j in range(m+1)] for i in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if seq1[i-1] == seq2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])
    return dp[n][m]
##------------------------------------------------------------
## Question 5: Longest Common Subsequence of Three Sequences
def lcs3(a, b, c):
    n, m, l = len(a), len(b), len(c)
    dp = [[[0 for _ in range(l+1)] for _ in range(m+1)] for _ in range(n+1)]
    
    for i in range(1, n+1):
        for j in range(1, m+1):
            for k in range(1, l+1):
                if a[i-1] == b[j-1] == c[k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])
    
    return dp[n][m][l]
