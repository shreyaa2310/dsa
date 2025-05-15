#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& board, int row, int col, int rows, int cols) 
{
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;
    for (int j = 0; j < col; j++)
        if (board[row][j] == 1)
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < cols; i--, j++)
        if (board[i][j] == 1)
            return false;
    for (int i = row + 1, j = col - 1; i < rows && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row + 1, j = col + 1; i < rows && j < cols; i++, j++)
        if (board[i][j] == 1)
            return false;
    for (int i = row + 1; i < rows; i++)
        if (board[i][col] == 1)
            return false;
    for (int j = col + 1; j < cols; j++)
        if (board[row][j] == 1)
            return false;
    return true;
}
bool placeQueens(vector<vector<int>>& board, int rows, int cols, int queensToPlace, int startRow = 0) 
{
    if (queensToPlace == 0)
        return true;
    for (int i = startRow; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (isSafe(board, i, j, rows, cols))
            {
                board[i][j] = 1;
                if (placeQueens(board, rows, cols, queensToPlace - 1, i))
                    return true;
                board[i][j] = 0;
            }
        }
    }
    return false;
}
void printBoard(const vector<vector<int>>& board, int rows, int cols) {
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
            cout << (board[i][j] == 1 ? "Q " : ". ");
        cout << endl;
    }
}
int main() 
{
    int rows, cols, queens;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of queens to place: ";
    cin >> queens;
    if (queens > rows * cols) 
    {
        cout << "Too many queens for the board size!" << endl;
        return 0;
    }
    vector<vector<int>> board(rows, vector<int>(cols, 0));
    if (placeQueens(board, rows, cols, queens)) 
    {
        cout << "\nSolution:\n";
        printBoard(board, rows, cols);
    }
    else 
    {
        cout << "No solution possible for given input.\n";
    }
    return 0;
}
