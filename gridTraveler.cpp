#include <iostream>
#include <unordered_map>
#include <string>

double gridTraveler(int m, int n, std::unordered_map<std::string, double> &memo){
    std::string key = std::to_string(m) + ',' + std::to_string(n);
    if(memo.find(key) != memo.end()){
        return memo[key];
    }
    if(m == 1 && n == 1){
        return 1;
    }
    if(m == 0 || n == 0){
        return 0;
    }
    memo[key] = gridTraveler(m-1, n, memo) + gridTraveler(m, n-1, memo);
    return memo[key];
}

int main(){
    std::unordered_map<std::string, double> memo;
    printf("%.0f\n", gridTraveler(1,1, memo));
    printf("%.0f\n", gridTraveler(2,3, memo));
    printf("%.0f\n", gridTraveler(3,2, memo));
    printf("%.0f\n", gridTraveler(3,3, memo));
    printf("%.0f\n", gridTraveler(18,18, memo));
    return 0;
}