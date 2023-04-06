###---------------------------------------------------------------------------------####
## Question 1 Binary Search 
def binarySearch(arr, left, right, elem):
    mid = left + (right - left) // 2
    if right >= left:
        # If the element is in the middle of the array 
        if arr[mid] == elem:
            return mid 
        # If the element is in the left side of the array
        elif arr[mid] > elem:
            return binarySearch(arr, left, mid - 1, elem)
        else:
            return binarySearch(arr, mid + 1, right, elem)
    # If the element is not in the array
    else:
        return -1
    
def binary_search_index(arr, keys):
    lst_index = []
    for keys in keys:
        lst_index.append(binarySearch(arr,0,len(arr)-1,keys))

###---------------------------------------------------------------------------------####
## Question 2: Maximum Element
def getMajorityElement(a, left, right):
    # Base case: input subarray has only one element
    if left == right:
        return a[left]

    # Divide the input subarray into two halves
    mid = left + (right - left) // 2

    # Recursively find the majority element in the left and right halves
    left_majority = getMajorityElement(a, left, mid)
    right_majority = getMajorityElement(a, mid + 1, right)
    
    # If the left and right majorities are the same, that element is the majority element
    if left_majority == right_majority:
        return left_majority
    
    # Otherwise, count the occurrences of the left and right majorities in the entire input subarray
    left_count = 0
    for i in range(left, right + 1):
        if a[i] == left_majority:
            left_count += 1
    
    right_count = 0
    for i in range(left, right + 1):
        if a[i] == right_majority:
            right_count += 1
    
    # Return the majority element between the left and right majorities
    if left_count > (right - left + 1) // 2:
        return left_majority
    elif right_count > (right - left + 1) // 2:
        return right_majority
    else:
        return -1
###---------------------------------------------------------------------------------####
## Question 3: Improving Quick Sort 

###---------------------------------------------------------------------------------####
## Question 4: Number of Inversion 
def MergeSortInv(arr):
    inversions = 0 
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Recurisve call on each half 
        left_inversions = MergeSortInv(left_half)
        right_inversions = MergeSortInv(right_half)
        inversions += left_inversions + right_inversions

        # Mergeing the two sorted halves
        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i+=1 
            else:
                arr[k] = right_half[j]
                inversions += (mid - i) 
                j+=1
            k+=1                        
        while i < len(left_half):
            arr[k] = left_half[i]
            i+=1 
            k+=1 
        while j < len(right_half):
            arr[k] = right_half[j]
            j+=1 
            k+=1 
        
    return inversions
###---------------------------------------------------------------------------------####
## Question 5: Organizing a Lottery 
def cntlottery(arr, elem):
    if len(arr) <=1:
        if arr[0][0] <= elem and arr[0][1] >= elem:
            return 1 
        return 0 
    mid = len(arr) // 2

    left_arr = arr[:mid]
    right_arr = arr[mid:]

    left_cntlottery = cntlottery(left_arr, elem)
    right_cntlottery = cntlottery(right_arr, elem)

    return left_cntlottery + right_cntlottery

###---------------------------------------------------------------------------------####
## Question 6: Closest Points
