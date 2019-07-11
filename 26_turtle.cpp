// https://www.codechef.com/problems/CD1IT4

#include <iostream>
using namespace std;

#define MAX_ROWS 1000
#define MAX_COLU 1000
int DP[MAX_ROWS][MAX_COLU];

void print (int rows, int columns)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << DP[i][j] << ' ';
        cout << endl;
    }
}

int main ()
{
	int rows, columns, blocked;

    freopen("26_input.txt", "r", stdin);
    cin >> rows >> columns >> blocked;

	for (int i = 0; i < blocked; i++) { 
        int row, column;
        cin >> row >> column;
        if (row == 1 && column == 1) return 0;
        if (row == rows && column == columns) return 0;
        DP[--row][--column] = -1;

    }

    // print(rows,columns); cout << endl;

    bool flag = false;
    for (int i = 0; i < rows; i++) {
        if (DP[i][0] < 0) flag = true;
        DP[i][0] = flag ? 0 : 1;
    }

    flag = false;
    for (int i = 0; i < columns; i++) {
        if (DP[0][i] < 0) flag = true;
        DP[0][i] = flag ? 0 : 1;
    }

    // print(rows,columns); cout << endl;

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            if (DP[i][j] < 0) DP[i][j] = 0;
            else DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
    }

    // print(rows,columns);

    cout << DP[rows-1][columns-1] << endl;
}
