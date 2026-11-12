
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number of data points: ";
    cin >> n;

    double x[100], diff[100][100];

    cout << "Enter x and y values:\n";

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> diff[i][0];
    }

    // Calculate forward differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    // Print forward difference table
    cout << "\nForward Difference Table:\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << setw(8) << x[i];

        for (int j = 0; j < n-i; j++) {
            cout << setw(10) << diff[i][j];
        }

        cout << "\n";
    }

    return 0;
}
