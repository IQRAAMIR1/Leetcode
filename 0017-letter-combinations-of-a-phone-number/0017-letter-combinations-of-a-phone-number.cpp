class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        vector<string> phone_map = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        string current_combination;
        backtrack(digits, 0, current_combination, result, phone_map);
        return result;
    }
    void backtrack(const string& digits, int index, string& current_combination, 
                   vector<string>& result, const vector<string>& phone_map) {
        if (index == digits.size()) {
            result.push_back(current_combination);
            return;
        }
        int digit = digits[index] - '0';
        for (char letter : phone_map[digit]) {
            current_combination.push_back(letter);
            backtrack(digits, index + 1, current_combination, result, phone_map);
            current_combination.pop_back(); 
        }
    }
};