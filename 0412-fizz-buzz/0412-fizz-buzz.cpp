class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n);
        for (int i = 1; i <= n; i++) {
            string result = "";
            
            int key = (i % 3 == 0) * 1 + (i % 5 == 0) * 2; 
    
            switch (key) {
                case 3: result = "FizzBuzz"; break;
                case 1: result = "Fizz"; break;
                case 2: result = "Buzz"; break;
                default: result = to_string(i);
            }
            answer[i - 1] = result;
        }
        
        return answer;
    }
};
