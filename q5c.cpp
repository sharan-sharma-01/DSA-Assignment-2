#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[n*(n+1)/2];
    cout << "Enter elements of lower triangular matrix (row by row): ";
    for (int i = 0; i < n*(n+1)/2; i++) {
        cin >> arr[i];
    }

    cout << "Lower Triangular Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << arr[(i*(i+1))/2 + j] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
