'''
 Write a function 'howSum(targetSum, numbers)' that takes in a
 targetSum and an array of numbers as arguments.

 The function should return an array containing any combination of
 elements that add up to exactly the targetSum. If there is no 
 combination that adds up to the targetSum , then return null.

 If there are multiple combinations possible, you may return any
 single one.
 '''

'''
Brute Force:
Time complexity: O(n^m *m)
Space complexity: O(m)

Memoized Implementation:
Time Complexity: O(n*m^2)
Space Complexity: O(m^2)
'''
def ihowSum(targetSum, numbers):
    global memo
    memo = {}
    ret = howSum(targetSum, numbers)
    del memo
    return ret


def howSum(targetSum, numbers):
    global memo
    if targetSum in memo:
        return memo[targetSum]
    if targetSum == 0:
        return []
    if targetSum < 0:
        return None

    for num in numbers:
        remainder =  targetSum - num
        remainderResult = howSum(remainder, numbers)
        if(remainderResult != None):
            remainderResult.append(num)
            memo[targetSum] = remainderResult
            return memo[targetSum]
    memo[targetSum] = None
    return None

if __name__ == "__main__":
    print(ihowSum(7, [2,3]))
    print(ihowSum(7, [2,4]))
    print(ihowSum(8, [2,3,5]))
    print(ihowSum(7, [5,3,4,7]))
    print(ihowSum(300, [7,14]))