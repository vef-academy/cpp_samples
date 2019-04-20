#include <iostream>
#include <vector>
#include <cmath>
using std::vector;
using std::cout;
using std::endl;

void swap4(int &a0, int &a1, int &a2, int &a3, bool isClockWise);

/******************************************************************************
    Method 1. Rotate one by one cycle O(n)
    a1 a2 a3 a1
    a3 b  b  a2
    a2 b  b  a3
    a1 a3 a2 a1
    First: Rotate a chain
        1           2           3               4
        a[0][0],    a[0][n-1],  a[n-1][n-1],    a[n-1][0]
        a[0][*],    a[*][n-1],  a[n-1][*],      a[*][0]
        ...
        a[0][n-2],  a[n-2][n-1],a[n-1][1],      a[1][0]
    Second: Rotate b chain
        a[1][1],    a[1][n-2],  a[n-2][n-2],    a[n-2][1]
******************************************************************************/
void rotate_method1(vector<vector<int>> &m, bool isClockWise){
    int N = m.size();
    for(int i = 0; i < std::floor(N/2); i++){
        for(int j = i; j < (N-1)-i; j++){
            // Get 4 element to swap
            swap4(m[i][j],
                  m[j][(N - 1) - i],
                  m[(N - 1) - i][(N - 1) - j],
                  m[(N - 1) - j][i],
                  isClockWise);
        }
    }
}

/****************************************************************************** 
    Method 2: O(n)
        Step 1: Transpose matrix 
            i: 0 -> n-1
            j: i+1 -> n-1
        Step 2: Reverse row (Right rotate)
                Reverse col (Left rotate)

******************************************************************************/
void rotate_method2(vector<vector<int>> &m, bool isClockWise){
    int N = m.size();
    // Find transpose matrix
    for(int i = 0; i < N-1; i++){
        for(int j = i + 1; j < N; j++){
            std::swap(m[i][j],m[j][i]);
        }
    }
    
    if(isClockWise){
        // Reverse in row of the tranpose matrix
        for(int row = 0; row < N; row++){
            for(int l = 0, r = N-1; l < r; l++, r--){
                std::swap(m[row][l], m[row][r]);
            }
        }
    }else{
        // Reverse in column of the tranpose matrix
        for(int col = 0; col < N; col++){
            for(int u = 0, d = N-1; u < d; u++, d--){
                std::swap(m[u][col], m[d][col]);
            }    
        }
    }    
}

/* Rotate 4 element following clockwise or counter-clockwise direction */
void swap4(int &a0, int &a1, int &a2, int &a3, bool isClockWise)
{
    int tmp = a0;
    if (isClockWise){
        std::swap(tmp, a1);
        std::swap(tmp, a2);
        std::swap(tmp, a3);
        std::swap(tmp, a0);
    }else{
        std::swap(tmp, a3);
        std::swap(tmp, a2);
        std::swap(tmp, a1);
        std::swap(tmp, a0);
    }
}

/* Utility function */
void print (const vector<vector<int>>& matrix){
    for (auto it : matrix){
        for (auto itr: it){
            cout << itr << ", ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> testMatrix{ {1, 2, 3, 4, 5, 6},
                                    {7, 8, 9, 10, 11, 12},
                                    {13, 14, 15, 16, 17, 18},
                                    {19, 20, 21, 22, 23, 24},
                                    {25, 26, 27, 28, 29, 30},
                                    {31, 32, 33, 34, 35, 36}};
    cout << "current matrix" << endl;
    print(testMatrix);
    
    cout << "Rotate matrix 90 degree clockwise direction" << endl;
    rotate_method2(testMatrix, true);
    print(testMatrix);

    cout << "Rotate matrix 90 degree counterclockwise direction" << endl;
    rotate_method2(testMatrix, false);
    print(testMatrix);
}