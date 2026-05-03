#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<vector<int>> multiplyMatrices(
    const vector<vector<int>>& mat1,
    const vector<vector<int>>& mat2) {

    int r1 = mat1.size();
    int c1 = mat1[0].size();
    int r2 = mat2.size();
    int c2 = mat2[0].size();

    if (c1 != r2) {
        throw invalid_argument("Matrix dimensions do not match for multiplication.");
    }

    vector<vector<int>> result(r1, vector<int>(c2, 0));

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> mat1 = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> mat2 = {
        {5, 6},
        {7, 8}
    };

    try {
        vector<vector<int>> result = multiplyMatrices(mat1, mat2);

        cout << "Result matrix:\n";
        for (const auto& row : result) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

    } catch (const exception& e) {
        cout << e.what();
    }

    return 0;
}