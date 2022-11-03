'''
Wrtie a function 'canConstruct(target, wordBank)' that accepts a 
target string and an array of strings.

The function should return a boolean indicating whether or not the
'target' can be constructed by concatenating elements of the
'wordBank' array.

You may reuse  elements of the 'wordBank' as many times as needed.
'''

'''
Brute Force:
Time complexity: O(n^m *m)
Space complexity: O(m^2)

Memoized Implementation:
Time Complexity: O(n*m^2)
Space Complexity: O(m^2)
'''

def canConstruct(target, wordBank, memo = {}):
    if (target in memo):
        return memo[target]

    if (target == ""):
        return True
    
    for word in wordBank:
        if (target.find(word) == 0):
            suffix = target[len(word):]
            if (canConstruct(suffix, wordBank, memo) == True):
                memo[target] = True
                return True
    memo[target] = False
    return False


if __name__ == "__main__":
    print(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])) # True
    print(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])) # False
    print(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])) # True
    print(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeee", "eeeee", "eeeeee"])) # False
