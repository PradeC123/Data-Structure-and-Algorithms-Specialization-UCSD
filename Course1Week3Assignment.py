###------------------------------------------------------------------------### 
### Question 1 : Money Change 

def coinchange(n):
    # list of available coins
    coin_change = [1,5,10]
    # variable to keep track of number of coins used
    count_coin = 0
    # continue until n becomes zero
    while (n != 0):
        # if n is greater than or equal to the maximum coin value available
        if n >= max(coin_change):
            # add one to the coin count
            count_coin += 1 
            # subtract the maximum coin value from n
            n -= max(coin_change)
        else: 
            # remove the maximum coin value from the list of available coins
            coin_change.remove(max(coin_change))
    # return the number of coins used to make change for n
    return count_coin


#n = int(input("Enter the input value: "))
#print(coinchange(n))

###------------------------------------------------------------------------### 
### Question 2 : Maximum Value of the Loot

def optimal_value_loot(capacity, weights, values):
    value = 0 # initialize the value to 0
    cost_per_weight = [values[i]/weights[i] for i in range(len(weights))] # calculate the cost per unit weight
    while(capacity!=0): # keep iterating while there is still capacity left
        indMaxweight = cost_per_weight.index(max(cost_per_weight)) # find the index of the item with the highest cost per unit weight
        min_cap = min(weights[indMaxweight],capacity) # calculate the minimum capacity that can be filled with the item
        capacity -= min_cap # decrease the remaining capacity by the amount of capacity filled with the item
        value += min_cap*cost_per_weight[indMaxweight] # increase the total value by the value of the capacity filled with the item
        cost_per_weight.remove(max(cost_per_weight)) # remove the item with the highest cost per unit weight from the list
    return round(value,4) # return the total value, rounded to 4 decimal places


#print(optimal_value_loot(10,[30],[500]))
#print(optimal_value_loot(50,[20,50,30],[60,100,120]))

###------------------------------------------------------------------------### 
### Question 3 : Car Fueling

def car_fueling(d,m,stop_arr):
    stop_cnt = 0      # initialize the number of stops made to 0
    stop_fueling = 0  # initialize the distance of the last fuel stop to 0
    stop_arr.append(d) 
     # append the destination to the list of stops
    for i in range(0,len(stop_arr)-1):  # iterate over the list of stops
        if stop_arr[i] + m < stop_arr[i+1]:  # if the car can't reach the next stop without refueling
            return -1  # return -1 indicating it's impossible to reach the destination
        if (stop_arr[i] <= m + stop_fueling) and (stop_arr[i+1] >= m + stop_fueling):  # if the car needs to refuel at the current stop
            stop_fueling = stop_arr[i]  # set the distance of the last fuel stop to the current stop
            stop_cnt += 1  # increment the number of stops made
        if stop_cnt == 0 and i == len(stop_arr) - 1:  # if no stops were made and the destination has been reached
            return 0  # return 0 indicating no stops were needed
    return stop_cnt  # return the number of stops made


d = 500
m = 200 
stop_arr = [50,200,350]
print(car_fueling(d,m,stop_arr))
#d = 10 
#m = 3 
#stop_arr = [1,2,5,9]

#d = 200 
#m = 250 
#stop_arr = [100, 150]

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
