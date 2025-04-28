#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int left = 0, right = size-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == key){
            return mid;
        }else{
            if(key < arr[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 200;
    int index = binarySearch(arr, size, key);
    cout << "Element found at index: " << index << endl;
    return 0;
}