#include <bits/stdc++.h>
using namespace std;

void getPositions(string text, string pattern, vector<int> &positions)
{
    int n = text.length();    // length of text
    int m = pattern.length(); // length of pattern
    int i, j;
    for (i = 0; i <= (n - m); i++)
    {
        int idx = i;
        for (j = 0; j < m; j++)
        {
            if (text[idx] == pattern[j])
            {
                idx++;
            }
            else
            {
                break;
            }
        }

        if (j == m)
        {
            positions.push_back(i);
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    if (pattern.length() > text.length())
    {
        cout << "Pattern ccannot be bigger than Text" << endl;
    }
    else
    {
        vector<int> positions;
        getPositions(text, pattern, positions);

        if (positions.size() > 0)
        {
            cout << "Pattern found at index: ";
            for (int ele : positions)
            {
                cout << ele << " ";
            }
        }
        else
        {
            cout << "Pattern not present in text" << endl;
        }
    }
    return 0;
}