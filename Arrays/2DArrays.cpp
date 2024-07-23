#include<bits/stdc++.h>
using namespace std;
void printMatrixRowWise(vector <vector<int>> matrix ){
for (int i = 0; i < matrix.size(); i++)
    {
       for(int j=0;j < matrix[i].size();j++){
        cout<<matrix[i][j]<<" ";
       }
       cout<<endl;
    }
}
void printMatrixColWise(vector <vector<int>> matrix, int col ){
for (int j = 0; j < col; j++)
    {
       for(int i=0;i < matrix.size();i++){
        cout<<matrix[i][j]<<" ";
       }
       cout<<endl;
    }
}

void printDiagonalElements(vector <vector<int>> matrix,int col,int row){
    for (int i = 0; i < row; i++)
    {
        cout<<matrix[i][i]<<" ";
    }
    
}

void transposeMatrix(vector <vector<int>> matrix,int col,int row ){
    for (int i = 0; i < row; i++)
    {
       for(int j=i;j < col;j++){
            swap(matrix[i][j],matrix[j][i]);
       }
    }
}
int main () {
    vector<vector<int>> matrix;
    vector<int> row1 = {1,2,3};
    vector<int> row2 = {4,5,6};
    vector<int> row3 = {7,8,9};

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    //matrix.size() --> number of rows
    // printMatrixRowWise(matrix);
    // printMatrixColWise(matrix,3);
    // transposeMatrix(matrix,3,3);
    // printMatrixRowWise(matrix);
    cout<<"--------------"<<endl;
    printDiagonalElements(matrix,3,3);
    return 0;
}

