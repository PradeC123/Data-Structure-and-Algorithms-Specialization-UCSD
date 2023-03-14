###------------------------------------------------------------------------### 
### Question 1 : Money Change 

def fueling_advrevenue(n):
    coin_change = [1,5,10]
    count_coin = 0
    while (n != 0):
        if n >= max(coin_change):
            count_coin += 1 
            n -= max(coin_change)
        else: 
            coin_change.remove(max(coin_change))
    return count_coin

#n = int(input("Enter the input value: "))
#print(fueling_advrevenue(n))

###------------------------------------------------------------------------### 
### Question 2 : Maximum Value of the Loot

def optimal_value_loot(capacity, weights, values):
    value = 0 
    cost_per_weight = [values[i]/weights[i] for i in range(len(weights))]
    while(capacity!=0):
        indMaxweight = cost_per_weight.index(max(cost_per_weight))
        min_cap = min(weights[indMaxweight],capacity)
        capacity -= min_cap
        value += min_cap*cost_per_weight[indMaxweight]
        cost_per_weight.remove(max(cost_per_weight))
    return round(value,4)

#print(optimal_value_loot(10,[30],[500]))
#print(optimal_value_loot(50,[20,50,30],[60,100,120]))

###------------------------------------------------------------------------### 
### Question 3 : Car Fueling

def car_fueling(d,m,stop_arr):
    stop_cnt = 0
    stop_fueling = 0 
    stop_arr.append(d)
    for i in range(0,len(stop_arr)-1):
        print(stop_arr[i])
        if stop_arr[i] + m < stop_arr[i+1]:
            return -1
        if (stop_arr[i] < m + stop_fueling) and (stop_arr[i+1] > m + stop_fueling):
            stop_fueling = stop_arr[i]
            stop_cnt += 1
        if stop_cnt == 0 and i == len(stop_arr) - 1:
            return 0
    return stop_cnt

#d = 950
#m = 400 
#stop_arr = [200, 375, 550, 950]
#d = 10 
#m = 3 
#stop_arr = [1,2,5,9]

#d = 200 
#m = 250 
#stop_arr = [100, 150]
#print(car_fueling(d,m,stop_arr))

###------------------------------------------------------------------------### 
### Question 4 : Maximum Advertisement Revenue 
def maxadrevenue(a_arr,c_arr):
    a_arr = sorted(a_arr)
    c_arr = sorted(c_arr)
    sum_rev = 0
    for i in range(len(a_arr)):
        sum_rev += a_arr[i]*c_arr[i]
    return sum_rev

###------------------------------------------------------------------------### 
### Question 5 : Collecting Signatures 

###------------------------------------------------------------------------### 
### Question 6 : Maximum Number of Prizes 
def max_price(n):
    sum = 1  # initialize the sum to 1
    cntr = 1  # initialize the counter to 1
    lst = []  # create an empty list to store the prices
    while (n >= sum):  # continue adding prices while n is greater than or equal to the current sum
        lst.append(cntr)  # add the current price to the list
        cntr += 1  # increment the counter
        sum += cntr  # update the sum to include the new price
    sum -= cntr  # undo the last price added (because it makes the sum greater than n)
    lst[-1] += n - sum  # add the remaining amount to the last price in the list
    return(lst)  # return the list of prices
            
#print(max_price(10))  # should output [1, 2, 3, 4]


###------------------------------------------------------------------------### 
### Question 7 : Maxnimum Salary

def last_num(n):
    digit = 0
    while(n!=0):
        digit = n % 10  # get the last digit of the number
        n = n // 10  # remove the last digit from the number
    if n == 0:
        return digit  # return the last digit of the number
    # note: this code will never be executed because the while loop will exit
    # when n becomes zero, so the function will always return in the if statement

def IsgreaterEqual(digit, maxdigit):
    if maxdigit == None:
        return True  # if maxdigit is None (i.e., no maximum has been set yet), then digit is greater or equal to it
    return last_num(digit) >= last_num(maxdigit)  # compare the last digits of digit and maxdigit

def LargestNumber(digit_arr):
    largest_str = ""  # initialize the output string
    while(len(digit_arr)!=0):
        max_digit = None  # initialize the maximum digit to None
        for digit in digit_arr:
            if IsgreaterEqual(digit, max_digit):
                max_digit = digit  # update the maximum digit if digit is greater or equal to it
        digit_arr.remove(max_digit)  # remove the maximum digit from the array
        largest_str += str(max_digit)  # add the maximum digit to the output string
    return largest_str  # return the output string
            
#print(LargestNumber([23,4,39,100]))  # should output "94323100"
