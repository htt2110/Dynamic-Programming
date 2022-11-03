 #include <iostream>
 #include <unordered_map>
 #include<vector>

 bool canConstruct(std::string target, std::vector<std::string> wordBank,  std::unordered_map<std::string, bool> &memo){
    if(memo.find(target) != memo.end()) return memo[target]; 
    if(target == "") return true;

    for(std::string word : wordBank){
        int idx = target.find(word);
        if(idx == 0){
            std::string suffix = target.substr(idx + word.length());
            if (canConstruct(suffix, wordBank, memo) == true){
                memo[target] = true;
                return true;
            }
        }   
    }
    memo[target] = false;
    return false;
 }

 int main(){
    std::unordered_map<std::string, bool> memo;
    std::cout <<canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << std::endl;
    std::cout <<canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo)<< std::endl;
    std::cout <<canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo)<< std::endl;
    std::cout <<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, memo)<< std::endl;
    return 0;
 }