#include <iostream>

class Matrix {
    private:
        int row, col;
        int** data;
    public:
        Matrix(int r, int c) : row(r), col(c) {
            data = new int*[row];
            for (int i = 0; i < row; ++i) {
                data[i] = new int[col];
                for (int j = 0; j < col; ++j) {
                    data[i][j] = 0;
                }
            }
        }
    Matrix() {
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    void set(int r, int c, int value) {
        if (r >= 0 && r < row && c >= 0 && c < col) {
            data[r][c] = value;
        } else {
            std::cout << "Index out of bounds!" << std::endl;
        }
    }
    int get(int r, int c) const {
        if (r >= 0 && r < row && c >= 0 && c < col) {
            return data[r][c];
        }
        std::cout << "Index out of bounds!" << std::endl;
        return -1;
        }

    void display() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};

int main() {
    Matrix mat(3, 3);
    mat.set(0, 0, 1);
    mat.set(1, 1, 5);
    mat.set(2, 2, 9);

    std::cout << "Matrix Contents: " << std::endl;
    mat.display();

    return 0;
}