//Approach: Take two dummy arrays one of size of the row and the other of size of column. 
//Now traverse through the array.If matrix[i][j]==0 then set dummy1[i]=0(for row) and dummy2[j]=0(for column).
//Now traverse through the array again and if dummy1[i]==0  || dummy2[j]==0 then arr[i][j]=0,else continue.

void setZeroes(vector<vector<int>>& matrix) 
{
        int rows = matrix.size(), cols = matrix[0].size();
        vector < int > dummy1(rows,-1), dummy2(cols,-1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
            }

        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
            if (dummy1[i] == 0 || dummy2[j]==0) {
                matrix[i][j] = 0;
            }
            }
        }
    }