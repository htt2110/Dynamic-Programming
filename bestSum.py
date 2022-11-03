'''
Write a function 'bestSum(targetSum, numbers)' that takes in a
targetSumand an array of numbers as arguments.

The function should return an array containing the shortest
combination of numbers that add up to exactly the targetSum.

If there is a tie for the shortest combination, you may return any
one of the shortest.
'''

'''
Brute Force:
Time complexity: O(n^m *m)
Space complexity: O(m^2)

Memoized Implementation:
Time Complexity: O(n*m^2)
Space Complexity: O(m^2)
'''


def ibestSum(targetSum, numbers):
    global memo
    memo = {}
    ret = bestSum(targetSum, numbers)
    del memo
    return ret

def bestSum(targetSum, numbers):
    global memo
    if (targetSum in memo):
        return memo[targetSum]
    if (targetSum == 0):
        return []
    if (targetSum < 0):
        return None 

    shortestCombination = None

    for num in numbers:
        remainder = targetSum - num
        remainderCombination = bestSum(remainder, numbers)
        if(remainderCombination != None):
            combination = remainderCombination[:]
            combination.append(num)
            # if combination is shorter that the current "shortest", update it
            print(len(combination))
            if (shortestCombination == None or len(combination) < len(shortestCombination)):
                shortestCombination = combination[:]
                
    memo[targetSum] = shortestCombination
    return shortestCombination

if __name__ == "__main__":
    print(ibestSum(7, [5,3,4,7]))
    # print(ibestSum(8, [2,3,5]))
    # print(ibestSum(8, [1,4,5]))
    # print(ibestSum(100, [1,5,25]))