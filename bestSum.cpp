 #include <iostream>
 #include <unordered_map>
 #include<vector>

std::vector<int>* bestSum(int targetSum, std::vector<int> &numbers, std::unordered_map<int, std::vector<int>*> &memo);

std::vector<int>* ibestSum(int targetSum, std::vector<int> numbers){
    std::unordered_map<int, std::vector<int>*> memo;
    std::vector<int>* ret = bestSum(targetSum, numbers, memo);
    return ret;
}

std::vector<int>* bestSum(int targetSum, std::vector<int> &numbers, std::unordered_map<int, std::vector<int>*> &memo){
    if(memo.find(targetSum) != memo.end()){
        return memo[targetSum];
    };
    if(targetSum == 0){
        return new std::vector<int>;
    };
    if(targetSum < 0){
        return nullptr;
    };

    std::vector<int>* shortestCombination = nullptr;

    for(auto num : numbers){
        int remainder = targetSum - num;
        std::vector<int>* remainderCombination = bestSum(remainder, numbers, memo);
        if(remainderCombination){
            std::vector<int>* combination = new std::vector<int> (*remainderCombination);
            combination->push_back(num);
            if(shortestCombination == nullptr || combination < shortestCombination){
                shortestCombination = new std::vector<int> (*combination);
            };
    }
}
memo[targetSum] = shortestCombination;
return shortestCombination;
}


typedef struct{
    int targetSum;
    std::vector<int> numbers;
}tuple;

int main(){
    std::vector<tuple> cases;
    // cases.push_back({7, {5,3,4,7}});
    cases.push_back({8, {2,3,5}});
    // cases.push_back({8, {1,4,5}});
    // cases.push_back({100, {1,5,25}});
    for(tuple x :cases){
        std::vector<int>* res = ibestSum(x.targetSum, x.numbers);
        if(res){ 
            for(auto i : *res){
                printf("%i ", i);
            }
        }
        printf("\n");
 }
    return 0;
}