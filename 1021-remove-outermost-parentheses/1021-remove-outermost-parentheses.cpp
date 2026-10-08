class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int lvl = 0;
        
        for (auto& c : s)
            if ((c == '(' && lvl++) || (c == ')' && lvl-- > 1))
                res += c;

        return res;
    }
};