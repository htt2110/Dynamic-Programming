/*
Write a gunction 'canSum(targetSum, numbers)' that takes in a
targetSum and an array of numbers as arguments.

The function should return a boolean indicating whether or not it 
is possible to generate the targetSum using numbers from the array.

Constraints:

You may use an element of the array as many times as needed.

You may assume that all input numbers are non-negative.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

// Declare the canSum function before initialization
bool canSum(int targetSum, const std::vector<int> &numbers, std::unordered_map<int, bool> &memo);

// Backtracking: go back to root node if solution not found at leaf node
bool icanSum(int targetSum, std::vector<int> numbers){
    std::unordered_map<int, bool> memo;
    bool ret = canSum(targetSum, numbers, memo);
    return ret;
}

// Bactrack function (Recursion)
bool canSum(int targetSum, std::vector<int> &numbers, std::unordered_map<int, bool> &memo){
    if (memo.find(targetSum) != memo.end()){
        return memo[targetSum];
    }
    if (targetSum == 0){
        return true;
    }

    if (targetSum < 0){
        return false;
    }

    for(int num : numbers){
        int remainder = targetSum - num;
        if(canSum(remainder, numbers, memo) == true){
            memo[targetSum] = true;
            return memo[targetSum];
        }
    }
    memo[targetSum] = false;
    return false;
}

typedef struct{
    int targetSum;
    std::vector<int> numbers;
}tuple;

int main(){
    std::vector<tuple> cases;
    cases.push_back({7, {2,3}});
    cases.push_back({7, {5,3,4,7}});
    cases.push_back({7, {2,4}});
    cases.push_back({8, {2,3,5}});
    cases.push_back({300, {7,14}});
    
    for(tuple x : cases){
        printf(icanSum(x.targetSum, x.numbers) ? "true" : "false" );
        printf("\n");
    }
}