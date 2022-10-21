#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isNull(string s)
    {
        return s.compare("null") == 0;
    }

    bool checkIfAnagram(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        bool isEqual = true;
        vector<int> visitedInS2{};

        for (int i = 0; i < s1.length(); i++)
        {
            for (int j = 0; j < s1.length(); j++)
            {
                // if (j in visitedInS2)
                //     continue;
                if (s1[i] == s2[j])
                {
                    // visitedInS2.insert();
                    visitedInS2.push_back(j);
                    s2[j] = '0';
                }
            }
        }

        if (visitedInS2.size() != s1.length())
        {
            isEqual = false;
        }
        return isEqual;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> B;
        vector<string> temp;
        for (int i = 0; i < strs.size(); i++)
        {
            temp.clear();
            if (isNull(strs[i]))
            {
                continue;
            }

            temp.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (!isNull(strs[j]) && checkIfAnagram(strs[i], strs[j]))
                {
                    temp.push_back(strs[j]);
                    strs[j] = "null";
                }
            }

            vector<string> toAdd = temp;
            B.push_back(toAdd);
        }

        return B;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto tex = Solution().groupAnagrams(input);
    return 0;
}
