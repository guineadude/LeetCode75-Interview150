#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    int minChanges(std::string s) {
        auto isEqual = [](char a, char b) { return a == b; };
        int changes {};
        for (auto it = s.begin(); it != s.end(); it+=2) {
            char a = *it;
            char b = *std::next(it);
            bool bEqual = isEqual(a, b);
            if(!bEqual)
                ++changes;
        }
        return changes;
    }
};

int main() {
    Solution s;
    auto x = s.minChanges("0000");
    std::cout << x;
}