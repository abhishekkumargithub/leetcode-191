we need to rotate the matrix by 90 degree
Approach:
1. Bruteforce Approach:
take another dummy matrix of n*n, and then first row of matrix and put it in the last column of dummy matrix and second row in second last column and so on.
code:
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
  int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
  return rotated;
}

2. Optimized Approach
Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
Step 2: Reverse each row of the matrix.

Code:
void rotate(vector < vector < int >> & matrix) {
  int n = matrix.size();
  //transposing the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  //reversing each row of the matrix
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}