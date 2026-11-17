#include <vector>
#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
struct SubstrDiv 
{
    std::string str;
    std::size_t startIndex;
    std::size_t len;
};
    int minimumChanges(std::string s, int k) 
    {
        const std::size_t n {s.size()};
        const std::size_t parts {static_cast<std::size_t>(k)};

        // starts[j] = index where piece j begins (starts[0] is always 0)
        // first partition: every piece length 2, last piece takes the rest
        std::vector<std::size_t> starts(parts);
        for (std::size_t j {}; j < parts; ++j)
            starts[j] = 2 * j;

        int leastDiffs {INT_MAX};

        while (true)
        {
            // build the k pieces for this partition - they always cover all of s
            std::vector<SubstrDiv> subs;
            for (std::size_t j {}; j < parts; ++j)
            {
                const std::size_t end {j + 1 < parts ? starts[j + 1] : n};
                subs.push_back(SubstrDiv{
                    .str = s.substr(starts[j], end - starts[j]),
                    .startIndex = starts[j],
                    .len = end - starts[j] }
                );
            }

            int currentDiffs {};

            //for each sub
            for(auto& sub : subs)
            {
                // compare characters from ends
                for(std::size_t leftPointer {}, rightPointer {sub.len - 1}; leftPointer < rightPointer; ++leftPointer, --rightPointer)
                {
                    if(sub.str[leftPointer] != sub.str[rightPointer])
                        ++currentDiffs;
                }
            }

            if(currentDiffs < leastDiffs)
                leastDiffs = currentDiffs;

            // advance to the next partition (like an odometer):
            // find the rightmost cut that can move right by 1 while still
            // leaving at least 2 chars for it and every piece after it
            std::size_t j {parts - 1};
            while (j > 0 && starts[j] + 1 + 2 * (parts - j) > n)
                --j;

            if (j == 0) // no cut can move -> every partition has been checked
                break;

            ++starts[j];

            // reset every cut after j back to its tightest position
            for (std::size_t i {j + 1}; i < parts; ++i)
                starts[i] = starts[i - 1] + 2;
        }

        return leastDiffs;
    }
};

int main()
{
    Solution s;
    s.minimumChanges("abcac", 2);
}