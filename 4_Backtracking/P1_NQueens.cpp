#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>& board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n){
    
    // check in the current row but only left side of the current column in the current row,
    // because on right side, for sure now queens will be there in current row
    for(int i=0; i<col; i++){
        if(board[row][i]) return false;
    }

    // check upper diagonal on left side
    for(int i=row, j=col; i>=0 && j >=0; i--, j--){
        if(board[i][j]) return false;
    }

    // check lower diagonal on left side
    for(int i=row, j=col; i< n && j >= 0; i++, j--){
        if(board[i][j]) return false;
    }

    return true;
}

void solveNQueens(vector<vector<int>>& board, int col, int& count, int n){
    if(col == n){
        printBoard(board, n);
        count++;
        return;
    }

    for(int i=0; i<n; i++){
        if(isSafe(board, i, col, n)){
            board[i][col] = 1;
            solveNQueens(board, col + 1, count, n);
            board[i][col] = 0;
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    int n;
    cin >> n;
    vector<vector<int>> board (n, vector<int>(n, 0));
    int count = 0;
    solveNQueens(board, 0, count, n);
    cout << "\nTotal solutions: " << count << endl;
    return 0;
}