'''
Question:
Say that you are a traveler on a 2D grid. You begin in the 
top-left corner and your goal is to travel to the bottom-right
corner. You may only move down or right.
 
In how many ways can you travel to the goal on a grid with
dimensions m*n?
'''


'''
Brute Force:
Time complexity: O(2^n+m)
Space complexity: O(n+m)

Memoized Approach:
Time complexity: O(n*m)
Space complexity: O(n+m)
'''

def gridTraveler(m,n, memo = {}):
    key = str(m) + ',' + str(n)
    if (key in memo):
        return memo[key]
    if (m == 1 and n == 1):
        return 1
    if(m == 0 or n == 0):
        return 0
    memo[key] = gridTraveler(m-1, n, memo) + gridTraveler(m, n-1, memo)
    return memo[key]

if __name__ == "__main__":
    print(gridTraveler(1,1)) # 1
    print(gridTraveler(2,3)) # 3
    print(gridTraveler(3,2)) # 3
    print(gridTraveler(3,3)) # 6
    print(gridTraveler(18,18)) # 2333606220