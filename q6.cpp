#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

void printMatrix(Element mat[], int terms) {
    cout << "Row Col Val\n";
    for (int i = 0; i < terms; i++) {
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << "\n";
    }
}

void transpose(Element mat[], Element trans[], int terms) {
    int k = 0;
    for (int i = 0; i <= mat[terms-1].col; i++) {
        for (int j = 0; j < terms; j++) {
            if (mat[j].col == i) {
                trans[k].row = mat[j].col;
                trans[k].col = mat[j].row;
                trans[k].val = mat[j].val;
                k = k + 1;
            }
        }
    }
}

int add(Element a[], int ta, Element b[], int tb, Element sum[]) {
    int i = 0, j = 0, k = 0;
    while (i < ta && j < tb) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k] = a[i];
            i = i + 1;
            k = k + 1;
        } else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col)) {
            sum[k] = b[j];
            j = j + 1;
            k = k + 1;
        } else {
            sum[k].row = a[i].row;
            sum[k].col = a[i].col;
            sum[k].val = a[i].val + b[j].val;
            i = i + 1;
            j = j + 1;
            k = k + 1;
        }
    }
    while (i < ta) sum[k++] = a[i++];
    while (j < tb) sum[k++] = b[j++];
    return k;
}

void multiply(Element a[], int ta, Element b[], int tb, Element prod[]) {
    int k = 0;
    for (int i = 0; i < ta; i++) {
        for (int j = 0; j < tb; j++) {
            if (a[i].col == b[j].row) {
                prod[k].row = a[i].row;
                prod[k].col = b[j].col;
                prod[k].val = a[i].val * b[j].val;
                k = k + 1;
            }
        }
    }
    printMatrix(prod, k);
}

int main() {
    Element a[3] = {{0, 0, 1}, {0, 2, 2}, {1, 1, 3}};
    Element b[3] = {{0, 0, 4}, {0, 2, 5}, {1, 1, 6}};

    Element trans[3];
    transpose(a, trans, 3);
    printMatrix(trans, 3);

    Element sum[10];
    int tsum = add(a, 3, b, 3, sum);
    printMatrix(sum, tsum);

    Element prod[10];
    multiply(a, 3, b, 3, prod);

    return 0;
}
