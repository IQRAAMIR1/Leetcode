class Solution {
public:
    int romanToInt(string s) {
      unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int prevValue = 0;
    
    for (int i = s.length() - 1; i >= 0; --i) {
        int currentValue = roman[s[i]];
        
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }
        
        prevValue = currentValue;
    }
    
    return result;
}

int main() {
    string s;
    cout << "Enter a Roman numeral: ";
    cin >> s;
    cout << "Integer value: " << romanToInt(s) << endl;
    return 0;
}
  
 
};