#include <iostream>
const int N = 9;

using namespace std;

// https://www.sudokuwiki.org/Weekly_Sudoku.asp?puz=28
int grid [N][N] = {
        {6, 0, 0, 0, 0, 8, 9, 4, 0},
        {9, 0, 0, 0, 0, 6, 1, 0, 0},
        {0, 7, 0, 0, 4, 0, 0, 0, 0},
        {2, 0, 0, 6, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 9, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 3, 0},
        {8, 0, 0, 0, 0, 1, 6, 0, 0}
};

void print_sudoku() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid [i][j] << " ";
        }
        cout << '\n';
    }
}

bool no_zeros(int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid [row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool num_in_col(int &col, int &num) {
    for (int row = 0; row < N; row++) {
        if (grid [row][col] == num) {
            return true;
        }
    }
    return false;
}

bool num_in_row(int &row, int &num) {
    for (int col = 0; col < N; col++) {
        if (grid [row][col] == num) {
            return true;
        }
    }
    return false;
}

bool num_in_box(int &num_row, int &num_col, int &num) {
    int begin_row = num_row - num_row % 3;
    int begin_col = num_col - num_col % 3;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid [row + begin_row][col + begin_col] == num) {
                return true;
            }
        }
    }
    return false;
}

bool check_valid(int row, int col, int num) {
    if (num_in_row(row, num) || num_in_col(col, num) || num_in_box(row, col, num)) {
        return false;
    }
    return true;
}

bool solve_sudoku() {
    int row, col;
    if (!no_zeros(row, col)) {
        return true;
    }
    for (int num = 1; num <= N; num++) {
        if (check_valid(row, col, num)) {
            grid [row][col] = num;
            if (solve_sudoku()) {
                return true;
            }
            grid [row][col] = 0;
        }
    }
    return false;
}

int main() {
    if (solve_sudoku()) {
        cout << "Sudoku solved!\n";
        print_sudoku();
    }
    else {
        cout << "No solution found.\n";
    }
    return 0;
}
