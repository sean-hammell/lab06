// EECS 348 Lab 6
// Sean Hammell

#include <fstream>
#include <iostream>
#include <string>

static constexpr int N = 100;

void ReadFile(int *size, int A[N][N], int B[N][N]);
void PrintMatrix(int size, int A[N][N]);
void MatrixSum(int size, int A[N][N], int B[N][N]);
void MatrixProduct(int size, int A[N][N], int B[N][N]);
void MatrixDifference(int size, int A[N][N], int B[N][N]);

int main() {
  int size;
  int A[100][100];
  int B[100][100];

  ReadFile(&size, A, B);

  std::cout << "\nMatrix A:\n";
  PrintMatrix(size, A);

  std::cout << "\nMatrix B:\n";
  PrintMatrix(size, B);

  MatrixSum(size, A, B);
  MatrixProduct(size, A, B);
  MatrixDifference(size, A, B);

  return 0;
}

// Reads the size and contents of matrices A and B from "matrix_input.txt"
void ReadFile(int *size, int A[N][N], int B[N][N]) {
  std::fstream file;
  while (true) {
    std::string file_name;
    std::cout << "\nInput file: ";
    std::cin >> file_name;

    file.open(file_name, std::ios::in);
    if (!(file.is_open())) {
      std::cout << "Invalid file...\n";
      continue;
    }

    file >> *size;
    if (*size > N) {
      std::cout << "Declared matrix size of " << *size << " is too large...\n";
      std::cout << "Maximum matrix size: " << N << "\n";
      file.close();
      continue;
    }

    break;
  }

  for (int row = 0; row < *size; ++row) {
    for (int col = 0; col < *size; ++col) {
      file >> A[row][col];
    }
  }

  for (int row = 0; row < *size; ++row) {
    for (int col = 0; col < *size; ++col) {
      file >> B[row][col];
    }
  }

  file.close();
}

// Displays the contents of the matrix.
void PrintMatrix(int size, int A[N][N]) {
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      std::cout << A[row][col] << '\t';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

// Calculates the sum of two matrices A and B.
void MatrixSum(int size, int A[N][N], int B[N][N]) {
  int C[N][N];
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      C[row][col] = A[row][col] + B[row][col];
    }
  }

  std::cout << "\nMatrix Sum (A + B):\n";
  PrintMatrix(size, C);
}

// Calculates the product of two matrices A and B.
void MatrixProduct(int size, int A[N][N], int B[N][N]) {
  int C[N][N];
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      C[row][col] = 0;
      for (int i = 0; i < size; ++i) {
        C[row][col] += A[row][i] * B[i][col];
      }
    }
  }

  std::cout << "\nMatrix Product (A * B):\n";
  PrintMatrix(size, C);
}

// Calculates the difference of two matrices A and B.
void MatrixDifference(int size, int A[N][N], int B[N][N]) {
  int C[N][N];
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      C[row][col] = A[row][col] - B[row][col];
    }
  }

  std::cout << "\nMatrix Difference (A - B):\n";
  PrintMatrix(size, C);
}
