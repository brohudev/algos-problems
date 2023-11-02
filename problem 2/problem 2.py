def max_difference(arr, low, high):
    if low == high:
        return 0
    # find the mid point.  
    mid = (low + high) // 2
    # Find the maximum difference in the left and right subarrays
    max_difference_left = max_difference(arr, low, mid)
    max_difference_right = max_difference(arr, mid + 1, high)
    # Find the minimum and maximum values in the left and right subarrays
    # used to compare at the end and return the maximum delta. 
    min_left = min(arr[low:mid + 1])
    max_right = max(arr[mid + 1:high + 1])
    # Calculate the maximum difference that can be obtained by taking the min of left
    # subarray and max of the right subarray
    max_difference_cross = max_right - min_left
    # Return the maximum of the three differences
    return max(max_difference_left, max_difference_right, max_difference_cross)
# Input
n = int(input())
arr = list(map(int, input().split()))
# Find the maximum profit using divide and conquer
result = max_difference(arr, 0, n - 1)

# Output the result
print(max(0, result))