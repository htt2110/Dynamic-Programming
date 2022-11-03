import time
'''
Dyanmic Programming 

Fibonacci Series Memoization implementation
Store values of sub-trees for utlization to avoid 
duplicate calculation.

Time complexity: O(n)
Space complexity: O(n)
'''
def fib(n):
    global memo
    if (n in memo):
        return memo[n]
    if (n <=2):
        return 1
    memo[n] = fib(n-1) + fib(n-2)
    return memo[n]
global memo
memo = {}
start = time.time()
print(fib(6))
print(fib(7))
print(fib(8))
print(fib(50))
print(time.time()- start)