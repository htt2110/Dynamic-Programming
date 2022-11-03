#include <iostream>
#include <unordered_map>


/*
Too slow with O(2^n) time complexity
*/
// int fib(int n){
//     if (n <= 2){
//         return 1;    
//     }
//     return fib(n-1)+fib(n-2);
// }

double fib(int n, std::unordered_map<int, double> &memo){
    if (memo.find(n) != memo.end()){
        return memo[n];
    }
    else{
    if (n <= 2){
        memo[n] = 1;  
    }
    else{
    memo[n] = fib(n-1, memo)+fib(n-2,memo);
    }
    }
    return memo[n];
}

// Using Memoization
//   use hash maps, keys will be arg to function, value will be the return value

int main(){
    std::unordered_map<int, double> memo;
    printf("%.0f\n", fib(6, memo));
    printf("%.0f\n", fib(7, memo));
    printf("%.0f\n", fib(8, memo));
    printf("%.0f\n", fib(50, memo));
    return 0;
}