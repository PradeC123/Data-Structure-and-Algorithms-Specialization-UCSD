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

###---------------------------------------------------------------------------------####
## Question 2: Maximum Element

###---------------------------------------------------------------------------------####
## Question 5: Organizing a Lottery 

###---------------------------------------------------------------------------------####
## Question 6: Closest Points

