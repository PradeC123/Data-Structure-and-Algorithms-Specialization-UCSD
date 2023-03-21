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