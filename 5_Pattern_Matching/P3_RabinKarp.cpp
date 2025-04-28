#include <bits/stdc++.h>
using namespace std;

const int base = 26; // Base can be anything you choose

int calculateHash(const string& str, int m)
{
    int hash = 0;
    for (int i = 0; i < m; i++)
    {
        int x = str[i] - 'A' + 1;
        hash = hash * base + x;
    }
    return hash;
}

void rabinkarp(const string& text, const string& pattern, vector<int>& pos)
{
    int n = text.length(), m = pattern.length();
    if (n < m) return;

    int hashPattern = calculateHash(pattern, m);
    int hashText = calculateHash(text, m);

    // Precompute base^(m-1)
    int baseM = 1;
    for (int i = 1; i < m ; i++)
    {
        baseM = baseM * base;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (hashText == hashPattern)
        {
            if (text.substr(i, m) == pattern)
                pos.push_back(i);
        }

        // Slide window
        if (i < n - m)
        {
            int leftChar = text[i] - 'A' + 1;
            int rightChar = text[i + m] - 'A' + 1;

            hashText = (hashText - leftChar * baseM) * base + rightChar;
        }
    }
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    if (text.length() < pattern.length())
    {
        cout << "Pattern cannot be greater than text" << endl;
        return 0;
    }

    vector<int> pos;
    rabinkarp(text, pattern, pos);

    if (pos.empty())
    {
        cout << "Pattern not present in text" << endl;
    }
    else
    {
        cout << "Pattern found at index: ";
        for (int idx : pos)
            cout << idx << " ";
        cout << endl;
    }

    return 0;
}
