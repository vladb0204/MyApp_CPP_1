#include <iostream>

using namespace std;

void printTable(int cells[]) {
    int nums[4][4];
    for (int i = 0; i < 16; i++) {
        nums[i / 4][i % 4] = cells[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (nums[i][j] == 0) {
                cout << "\t";
            } else {
                cout << nums[i][j] << "\t";
            }
        }

        cout << endl;
    }
}


bool checkWinner(int cells[]) {
    int count = 0;
    for (int i = 0; i < 15; i++) {
        if (cells[i] == i + 1) {
            count += 1;
        }
    }

    if (count == 15) {
        cout << "U've won!" << endl;
        return true;
    }

    return false;
}


void inputCell(int cells[], int move, int &coord) {
    if (move == 2) {
        swap(cells[coord], cells[coord - 4]);
    } else if (move == 8) {
        swap(cells[coord], cells[coord + 4]);
    } else if (move == 4) {
        swap(cells[coord], cells[coord + 1]);
    } else if (move == 6) {
        swap(cells[coord], cells[coord - 1]);
    }
}


void moveInput(int cells[], int &current) {
    int up = 8, down = 2, left = 4, right = 6;
    cout << "Where u wanna go?" << endl << "up = 8, down = 2, left = 4, right = 6" << endl;
    int move; cin >> move;
    if (move == 2) {
        if (current + 4 > 15) {
            cout << "U can't move there! Try again" << endl;
            moveInput(cells, current);
        } else {
            current += 4;
            inputCell(cells, move, current);
        }
    } else if (move == 8) {
        if (current - 4 < 0) {
            cout << "U can't move there! Try again" << endl;
            moveInput(cells, current);
        } else {
            current -= 4;
            inputCell(cells, move, current);
        }
    } else if (move == 4) {
        if (current % 4 - 1 < 0) {
            cout << "U can't move there! Try again" << endl;
            moveInput(cells, current);
        } else {
            current -= 1;
            inputCell(cells, move, current);
        }
    } else if (move == 6) {
        if (current % 4 + 1 > 3) {
            cout << "U can't move there! Try again" << endl;
            moveInput(cells, current);
        } else {
            current += 1;
            inputCell(cells, move, current);
        }
    } else {
        cout << "You can input only these numbers: 2 4 6 8" << endl;
        moveInput(cells, current);
    }
}


int main() {
    int nums[] = {3, 2, 1, 4, 9, 11, 12, 5, 6, 7, 8, 10, 14, 15, 13, 0};
    int start_coord = 15; // The coordinate where number 0 is located
    while (true) {
        printTable(nums);
        moveInput(nums, start_coord);
        if (checkWinner(nums)) {
            break;
        }
    }
}