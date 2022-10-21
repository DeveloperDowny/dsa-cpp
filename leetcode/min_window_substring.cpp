#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool doesContain(string &t, char mChar)
    {
        bool doesContain = false;
        int temp2 = 0;
        while (temp2 < t.length())
        {
            if (t[temp2] == mChar)
            {
                t[temp2] = '0';
                doesContain = true;
                break;
            }
            temp2++;
        }
        return doesContain;
    }

    bool window(int w_start, int w_end, string t, string s)
    {
        string tempT = t;
        int temp = w_start;
        int count = t.length();
        while (temp <= w_end)
        {
            if (doesContain(tempT, s[temp]))
            {

                count--;
            }

            if (w_end - temp < count)
            {
                return false;
            }
            temp++;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        if (s.length() == t.length())
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (!doesContain(t, s[i]))
                {
                    return "";
                }
            }

            // while (/* condition */)
            // {
            //     doesContain
            // }

            return s;
            // return (s.compare(t) == 0 ? s : "");
        }
        int w_size = t.length();
        while (w_size <= s.length())
        {
            int w_start = 0;
            while (w_start + w_size <= s.length())
            {
                if (window(w_start, w_start + w_size - 1, t, s))
                {
                    if (w_start == w_start + w_size - 1)
                    {
                        return string(1, s[w_start]);
                    }
                    return s.substr(w_start, w_size);
                    //  - 1);
                }
                w_start++;
            }
            w_size++;
        }
        return "";
    }
};

int main(int argc, char const *argv[])
{
    string test = Solution().minWindow(
        "fqqhcjlvvbxjliqttcmzcnidizbjbjajbsqeddbyhykshalcczegnojxnmirykazcsffwggdfqxosiqxiwdxkpuadfrbptbulibjphowzlksucpezubllxlpcesuxvolerutbjpaubuqdl",
        "uegvqttbi");
    cout << test << endl;
    return 0;
}

// rdm this means you are using wrong approach.
// this might be brute force approach
