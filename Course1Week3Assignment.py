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