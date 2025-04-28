#include<bits/stdc++.h>
using namespace std;
void classicMinMax(int arr[], int n){
    int minEle = arr[0];
    int maxEle = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] > maxEle){
            maxEle = arr[i];
        }
    }

    for(int i=1; i<n; i++){
        if(arr[i] < minEle){
            minEle = arr[i];
        }
    }

    cout << "Min Element: " << minEle << endl;
    cout << "Max Element: " << maxEle << endl;
}

int main() {
    int arr[] = {34, 76, 21, 90, -76, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    classicMinMax(arr, n);
    return 0;
}