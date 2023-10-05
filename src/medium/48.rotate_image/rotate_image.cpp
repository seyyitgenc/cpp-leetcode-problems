#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int column = 4;
        for (int i = 0; i < matrix.size(); i++)
        {
            column--;
            for (int j = 0; j < matrix.size() ; j++)
            {
                int temp = matrix[j][column];
                matrix[j][column] = matrix[i][j];
                matrix[i][j] = temp;
            }
            
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            printf("\n");
        }
        
    }
    void swap(int *x, int *y){
        
    }
};


int main(){
    Solution sol;
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // Input : [[1,2,3],
    //          [4,5,6],
    //          [7,8,9]]
   
    // Output: [[7,4,1],
    //          [8,5,2],
    //          [9,6,3]]
    sol.rotate(matrix);
    return 0;
}