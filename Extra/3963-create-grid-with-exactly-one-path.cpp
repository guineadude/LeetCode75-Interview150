// LeetCode 3963: Create Grid With Exactly One Path

#include <string>
#include <iostream>
#include <vector>
#include <cstddef>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {

        auto addChars = [&](){
            std::string s(n, '#');
            s[n-1] = '.'; //mark last row

            return s;
        };

        auto createString = [&](){
            std::vector<std::string> grid;
            grid.emplace_back(std::string(static_cast<size_t>(n), '.'));

            if(m == 1)
                return grid;

            for(int i{1}; i < m; ++i)
            {
                grid.emplace_back(addChars()); //add n nOF rows
            }
            return grid;
        };

        return createString();
    }
};

int main()
{
    Solution s;
    auto x = s.createGrid(2, 4);
    for (std::string s : x)
    {
        for(char c : s)
        {
            std::cout << c << " ";
        }
        std::cout << '\n';
    }
    return 0;
}
