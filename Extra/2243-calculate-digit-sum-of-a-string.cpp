// LeetCode 2243: Calculate Digit Sum of a String

#include <string>
#include <iostream>

class Solution {
public:

std::string digitSum(std::string s, int k)
{
    std::size_t lp {};
    std::size_t rp {};


    auto stepReadPointerTok = [&](){
        int sum {};
        std::size_t nfReads {};

        for (; nfReads < static_cast<std::size_t>(k) && rp < s.size(); ++rp)
        {
            sum += s[rp] - '0';
            ++nfReads;
        }
        for (char c : std::to_string(sum))
        {
            s[lp++] = c;
        }
        if(rp == s.size()) s.erase(lp);
    };

    while(true)
        {
            if(s.size() <= static_cast<std::size_t>(k)) break;
            while(rp < s.size())
            {
                stepReadPointerTok();
            }
            lp = 0;
            rp = 0;
        }

        return s;
    }
};

int main()
{
    Solution s;
    auto str = s.digitSum(std::string{"00000000"}, 3);
    std::cout << str;
    return 0;
}
