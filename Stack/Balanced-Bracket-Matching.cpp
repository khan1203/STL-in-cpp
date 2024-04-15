/*
Problem from HackerRank:
https://www.hackerrank.com/challenges/balanced-brackets/problem
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<char, int> symbols = {{'[', -1}, {'{', -2}, {'(', -3}, {']', 1}, {'}', 2}, {')', 3}};
string isBalanced(string s)
{
    stack<char> stc;
    for (char bracket : s)
    {
        if (symbols[bracket] < 0)
        {
            stc.push(bracket);
        }
        else
        {
            if (stc.empty())
                return "NO";
            char top = stc.top();
            stc.pop();
            if (symbols[top] + symbols[bracket] != 0)
            {
                return "NO";
            }
        }
    }
    if (stc.empty())
        return "YES";
    return "NO";
}

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        cout << isBalanced(str) << "\n";
    }
    return 0;
}
