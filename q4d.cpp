#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char arr[50][50];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (arr[i][k] != '\0' && arr[j][k] != '\0' && arr[i][k] == arr[j][k]) {
                k++;
            }
            if (arr[i][k] > arr[j][k]) {
                char temp[50];
                int t = 0;
                while (arr[i][t] != '\0') {
                    temp[t] = arr[i][t];
                    t++;
                }
                temp[t] = '\0';

                t = 0;
                while (arr[j][t] != '\0') {
                    arr[i][t] = arr[j][t];
                    t++;
                }
                arr[i][t] = '\0';

                t = 0;
                while (temp[t] != '\0') {
                    arr[j][t] = temp[t];
                    t++;
                }
                arr[j][t] = '\0';
            }
        }
    }

    cout << "Sorted strings:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
