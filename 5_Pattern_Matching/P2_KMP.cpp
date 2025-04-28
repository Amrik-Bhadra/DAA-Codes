#include <bits/stdc++.h>
using namespace std;

void kmp(string text, string pattern, vector<int>& positions, vector<int>& piTable){
    int i=0;
    int j=0;
    int n = text.length();
    int m = pattern.length();
    while(i < n){
        if(text[i] == pattern[j]){
            i++;j++;
            if(j == m){
                positions.push_back(i-j);
                j = piTable[j-1];
            }
        }else{
            if(j!=0){
                j = piTable[j-1];
            }else{
                i++;
            }
        }
    }
}

void formPiTable(string pattern, vector<int>& piTable){
    int m = pattern.length();
    int i=1; int j=0;
    
    // first index value always 0 as pehle koi match hoga nhi 1st elemnt k liye
    piTable[0] = 0;

    // runn till end of pattern
    while(i < m){

        // if character s match  --> prefix found
        if(pattern[i] == pattern[j]){
            j++;
            piTable[i] = j;
            i++;
        }else{

            // 
            if(j!=0){
                j = piTable[j-1];
            }else{
                piTable[i] = 0;
                i++;
            }
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
        vector<int> piTable(pattern.length());
        formPiTable(pattern, piTable);

        for(int ele: piTable){
            cout << ele << " ";
        }

        kmp(text, pattern, positions, piTable);

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