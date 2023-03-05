#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define N 5
using namespace std;

int main() {
    srand(time(0));
    float matrixMin(float[][N]);
    float matrixMax(float[][N]);
    float matrixTopCornerMax(float[][N]);
    float matrixBottomCornerMax(float[][N]);
    float matrixTopCornerMin(float[][N]);
    float matrixBottomCornerMin(float[][N]);

    float matrixMainDiagonalMax(float[][N]);
    float matrixMainDiagonalMin(float[][N]);

    float matrixSecondaryDiagonalMax(float[][N]);
    float matrixSecondaryDiagonalMin(float[][N]);

    float matrixAverage(float[][N]);
    float matrixTopCornerAverage(float[][N]);
    float matrixBottomCornerAverage(float[][N]);
    float matrixRowSum(float[][N], int);
    float matrixColumnSum(float[][N], int);
    float matrixRowMin(float[][N], int);
    float matrixRowMax(float[][N], int);
    float matrixColumnMin(float[][N], int);
    float matrixColumnMax(float[][N], int);
    float matrixRowAverage(float[][N], int);
    float matrixColumnAverage(float[][N], int);
    float matrixBottomCornerSum(float[][N]);
    float matrixTopCornerSum(float[][N]);
    float matrixGetClosestToAverage(float[][N]);

    float m[N][N];
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) m[i][j] = rand() / 10.;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << "\t" << m[i][j];
        cout << endl;
    }

    cout << "matrix min:\t\t" << matrixMin(m) << endl;
    cout << "matrix max:\t\t" << matrixMax(m) << endl;
    cout << "matrix top corner max:\t\t" << matrixTopCornerMax(m) << endl;
    cout << "matrix bottom corner max:\t\t" << matrixBottomCornerMax(m) << endl;
    cout << "matrix top corner min:\t\t" << matrixTopCornerMin(m) << endl;
    cout << "matrix bottom corner min:\t\t" << matrixBottomCornerMin(m) << endl;

    cout << "matrix main diagonal max:\t\t" << matrixMainDiagonalMax(m) << endl;
    cout << "matrix main diagonal min:\t\t" << matrixMainDiagonalMin(m) << endl;

    cout << "matrix secondary diagonal max:\t\t" << matrixSecondaryDiagonalMax(m) << endl;
    cout << "matrix secondary diagonal min:\t\t" << matrixSecondaryDiagonalMin(m) << endl;

    cout << "matrix average:\t\t" << matrixAverage(m) << endl;
    cout << "matrix top corner average:\t\t" << matrixTopCornerAverage(m) << endl;
    cout << "matrix bottom corner average:\t\t" << matrixBottomCornerAverage(m) << endl;
    for (int i = 0; i < N; i++) {
        cout << "matrix row sum:\t\t" << matrixRowSum(m, i) << endl;
        cout << "matrix column sum:\t\t" << matrixColumnSum(m, i) << endl;
        cout << "matrix row min:\t\t" << matrixRowMin(m, i) << endl;
        cout << "matrix row max:\t\t" << matrixRowMax(m, i) << endl;
        cout << "matrix column min:\t\t" << matrixColumnMin(m, i) << endl;
        cout << "matrix column max:\t\t" << matrixColumnMax(m, i) << endl;
        cout << "matrix row average:\t\t" << matrixRowAverage(m, i) << endl;
        cout << "matrix column average:\t\t" << matrixColumnAverage(m, i) << endl;
    }
    cout << "matrix bottom corner sum:\t\t" << matrixBottomCornerSum(m) << endl;
    cout << "matrix top corner sum:\t\t" << matrixTopCornerSum(m) << endl;
    cout << "matrix closest to average:\t\t" << matrixGetClosestToAverage(m) << endl;
}

float matrixMin(float matrix[][N]) {
    float res = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (res > matrix[i][j]) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}

float matrixMax(float matrix[][N]) {
    float res = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (res < matrix[i][j]) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}

float matrixTopCornerMax(float matrix[][N]) {
    float res = matrix[0][1];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (res < matrix[i][j]) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}

float matrixBottomCornerMax(float matrix[][N]) {
    float res = matrix[1][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (res < matrix[i][j]) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}

float matrixTopCornerMin(float matrix[][N]) {
    float res = matrix[0][1];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (res > matrix[i][j]) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}

float matrixBottomCornerMin(float matrix[][N]) {
    float res = matrix[1][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (res > matrix[i][j]) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}

float matrixMainDiagonalMax(float matrix[][N]) {
    float res = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (res < matrix[i][i]) {
            res = matrix[i][i];
        }
    }
    return res;
}

float matrixMainDiagonalMin(float matrix[][N]) {
    float res = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (res > matrix[i][i]) {
            res = matrix[i][i];
        }
    }
    return res;
}

float matrixSecondaryDiagonalMax(float matrix[][N]) {
    float res = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (res < matrix[i][N - 1 - i]) {
            res = matrix[i][N - 1 - i];
        }
    }
    return res;
}

float matrixSecondaryDiagonalMin(float matrix[][N]) {
    float res = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (res > matrix[i][N - 1 - i]) {
            res = matrix[i][N - 1 - i];
        }
    }
    return res;
}

float matrixAverage(float matrix[][N]) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += matrix[i][j];
        }
    }
    return res / (N * N);
}

float matrixTopCornerAverage(float matrix[][N]) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            res += matrix[i][j];
        }
    }
    return res / (2 * N);
}

float matrixBottomCornerAverage(float matrix[][N]) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            res += matrix[i][j];
        }
    }
    return res / (2 * N);
}

float matrixRowSum(float matrix[][N], int row) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        res += matrix[row][i];
    }
    return res;
}

float matrixColumnSum(float matrix[][N], int column) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        res += matrix[i][column];
    }
    return res;
}

float matrixRowMin(float matrix[][N], int row) {
    float res = matrix[row][0];
    for (int i = 0; i < N; i++) {
        if (res > matrix[row][i]) {
            res = matrix[row][i];
        }
    }
    return res;
}

float matrixRowMax(float matrix[][N], int row) {
    float res = matrix[row][0];
    for (int i = 0; i < N; i++) {
        if (res < matrix[row][i]) {
            res = matrix[row][i];
        }
    }
    return res;
}

float matrixColumnMin(float matrix[][N], int column) {
    float res = matrix[0][column];
    for (int i = 0; i < N; i++) {
        if (res > matrix[i][column]) {
            res = matrix[i][column];
        }
    }
    return res;
}

float matrixColumnMax(float matrix[][N], int column) {
    float res = matrix[0][column];
    for (int i = 0; i < N; i++) {
        if (res < matrix[i][column]) {
            res = matrix[i][column];
        }
    }
    return res;
}

float matrixRowAverage(float matrix[][N], int row) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        res = matrix[row][i];
    }
    return res / N;
}

float matrixColumnAverage(float matrix[][N], int column) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        res = matrix[i][column];
    }
    return res / N;
}

float matrixTopCornerSum(float matrix[][N]) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            res += matrix[i][j];
        }
    }
    return res;
}

float matrixBottomCornerSum(float matrix[][N]) {
    float res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            res += matrix[i][j];
        }
    }
    return res;
}

float matrixGetClosestToAverage(float matrix[][N]) {
    float average = matrixAverage(matrix);
    float res = INFINITY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (res > abs(abs(matrix[i][j]) - abs(average))) {
                res = matrix[i][j];
            }
        }
    }
    return res;
}