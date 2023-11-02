# ! this is broken dont use this algo to solve for the problem.
def canDivideConsecutive(nums, k):
    def helper(start):
        if start == len(nums):
            return True

        for size in range(1, k + 1):
            end = start + size - 1
            if end >= len(nums) or nums[end] in used:
                continue

            used.add(nums[end])
            if helper(start + size):
                return True

            used.remove(nums[end])

        return False

    nums.sort()  # Sort the input array
    used = set()  # Keep track of used numbers
    return helper(0)

# Input
nums = list(map(int, input().split()))
k = int(input())

# Call the function and print the result
result = canDivideConsecutive(nums, k)
print(result)
