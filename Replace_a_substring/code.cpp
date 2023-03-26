#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string &s1)
{
    vector<int> lps(s1.length());
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < s1.length())
    {
        if (s1[i] == s1[len])
        {
            len = len + 1;
            lps[i] = len;
            i = i + 1;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i = i + 1;
            }
            else
                len = lps[len - 1];
        }
    }

    return lps;
}

void modifyString(string &s, string &s1, string &s2)
{
    vector<int> lps = computeLPS(s1);
    int i = 0;
    int j = 0;
    vector<int> found;
    while (i < s.length())
    {
        if (s[i] == s1[j])
        {
            i = i + 1;
            j = j + 1;
        }
        if (j == s1.length())
        {
            found.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < s.length() && s1[j] != s[i])
        {
            if (j == 0)
                i = i + 1;
            else
                j = lps[j - 1];
        }
    }
    string ans = "";
    int prev = 0;
    for (int k = 0; k < found.size(); k++)
    {
        if (found[k] < prev)
            continue;
        ans.append(s.substr(prev, found[k] - prev));
        ans.append(s2);
        prev = found[k] + s1.size();
    }
    ans.append(s.substr(prev, s.length() - prev));
    cout << ans << endl;
}

int main()
{
    string S = "Got to do.. no other option";
    string S1 = "ot";
    string S2 = "--";
    modifyString(S, S1, S2);
    return 0;
}
