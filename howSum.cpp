/*
Write a function 'howSum(targetSum, numbers)' that takes in a
 targetSum and an array of numbers as arguments.

 The function should return an array containing any combination of
 elements that add up to exactly the targetSum. If there is no 
 combination that adds up to the targetSum , then return null.

 If there are multiple combinations possible, you may return any
 single one.
*/
 #include <iostream>
 #include <unordered_map>
 #include<vector>

std::vector<int>* howSum(int targetSum, std::vector<int> &numbers, std::unordered_map<int, std::vector<int>*> &memo);

 // Backtracking: go back to root node if solution not found at leaf node
std::vector<int>* ihowSum(int targetSum, std::vector<int> numbers){
    std::unordered_map<int, std::vector<int>*> memo;
    std::vector<int>* ret = howSum(targetSum, numbers, memo);
    return ret;
}

 std::vector<int>* howSum(int targetSum, std::vector<int> &numbers, std::unordered_map<int, std::vector<int>*> &memo){
    if(memo.find(targetSum) != memo.end()){
        return memo[targetSum];
    }
    if (targetSum == 0){
        return new std::vector<int>;
    };
    if(targetSum <0){
        return nullptr;
    };
    for(auto num : numbers){
        int remainder = targetSum - num;
        std::vector<int>* remainderResult = howSum(remainder, numbers, memo);
        if(remainderResult){
            remainderResult->push_back(num);
            memo[targetSum] = remainderResult;
            return memo[targetSum];
        }
    }
    memo[targetSum] = nullptr;
    return nullptr;
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
    for(tuple x :cases){
        std::vector<int>* res = ihowSum(x.targetSum, x.numbers);
        if(res){ 
            for(auto i : *res){
                printf("%i ", i);
            }
        }
        printf("\n");
 }
    return 0;
 }