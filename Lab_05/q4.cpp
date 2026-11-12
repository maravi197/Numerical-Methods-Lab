
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double y0 = 3, y1 = 11;
    double y3 = 69, y4 = 131;

    // Calculate missing value
    double missing = (4*y3 + 4*y1 - y0 - y4) / 6;

    cout << "Missing value = " << missing << "\n";

    double y[7] = {3, 11, missing, 69, 131, 223, 351};

    double diff[7][7];

    // Store original y values
    for (int i = 0; i < 7; i++) {
        diff[i][0] = y[i];
    }

    // Calculate forward differences
    for (int j = 1; j < 7; j++) {
        for (int i = 0; i < 7-j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    // Print difference table
    cout << "\nForward Difference Table:\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7-i; j++) {
            cout << setw(10) << diff[i][j];
        }
        cout << "\n";
    }

    return 0;
}
