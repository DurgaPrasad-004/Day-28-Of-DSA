#include<bits/stdc++.h>
using namespace std;

// Longest Consecutive Sequence
// Brute force

bool linearSearch(vector<int>&a, int num){
    int n = a.size();
    for(int i =0; i < n; i++){
        if(a[i] == num) return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a){
    int n = a.size();
    int longest = 1; 
    // pick a element and search for its consecutive number
    for(int i =0; i < n; i++){
        int x = a[i];
        int count = 1;
        // Search for consecutive number
        // using linear search
        while(linearSearch(a,x+1) == true){
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}
//Time Complexity: O(N2)
int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

// Better Approach
int longestSuccessiveElements(vector<int>&nums){
    int n = a.size();
    if(n == 0) return 0;
    
    // sort the arrray
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    // find the longest sequence
    for(int i = 0; i <n; i++){
        if(a[i] - 1 == lastSmaller){
            //a[i] is the next element of the current sequence
            count++;
            lastSmaller = a[i];
        }
        else if(a[i] != lastSmaller){
            count = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, count);
    }
    return longest;
}    
//Time Complexity: O(NlogN) + O(N)


// Optimal Approach
// We'll use data structure
int longestSuccessiveelements(vector<int>&a){
    int n = a.size();
    if(n == 0) return 0;
    int longestt = 0;
    unordered_set<int> set;
    //put all the array elements into the set:
    for(int i =0; i<n; i++){
        set.insert(a[i]);
    }
    // find the longest sequence
    for(auto it : set){
        // if 'it' is a starting number:
        if(set.find(it -1) == set.end()){
            // find the consecutive number:
            int count = 1;
            int x = it;
            while(set.find(x+1) != set.end()){
                x = x +1;
                count = count + 1;
            }
            longestt = max(longestt, count);
        }
    }
    return longestt;
}

//Time Complexity: O(N) + O(2*N) ~ O(3*N);


// Set matrix zone
void markRow(vector<vector<int>> &martrix, int n, int m){
    // set all the non zero elements as -1 the row i
    for(int j =0; j<m;j++){
        if(martrix[i][j] != 0){
            martrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &martrix, int n, int m){
    // set all the non zero elements as -1 the column j
    for(int i =0; i<n; i++){
        if(martrix[i][j]!= 0){
            martrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    // set -1 for rows and cols that contains 0. dont mark any of the 0 as -1;
    for(int i =0;i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, n, m);
                markCol(matrix, n, m);`
            }
        }
    }

    // finally mark all the -1 as 0;
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(martix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return martix;
}

int main(){
    vector<vector<int>> martix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = martix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "the final matrix is : ";
    for(auto it : ans){
        for(auto ele : it){
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}

// Better approach
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    int col[m] = {0};
    int row[n] = {0};
    for(int i = 0;  i < n; i++){
        for(int j = 0; j > m; j++){
            if(martix[i][j] == 0){
                row[i] = 1;
                col[j] =1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            if(row[i || col[j]]){
                martix[i][j] = 0;
            }
        }
    }
    return martix;
}    
//Time Complexity: O(2*(N*M))

// Optimal Approach
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    int col0 = 1; 
    // int col[m] = {0}; -> martix[0][j]
    // int row[n] = {0}; -> matrix[0][i]

    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
     for(int i = 0;  i < n; i++){
        for(int j = 0; j > m; j++){
            if(martix[i][j] == 0){
               martix[i][0] = 0;
               if( j != 0){
                martix[0][j] = 0;
               } else {
                col0 = 0;
               }
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(martix[i][j] != 0){
                if(martix[0][j] == 0 || martix[i][0] == 0){
                    martix[i][j] = 0;
                }
            }
        }
    }
    //step 3: Finally mark the 1st col & then 1st row:
    if(martix[0][0] == 0){
        for(int j = 0; j < m; j++) martix[0][j] = 0;
    }
    if(col0 == 0){
        for(int i = 0; i < n; i++){
            martix[i][0] = 0;
        }
    }
}

// Rotate matrix by 90* angle
// Brute force
vector< vector < int >> rotate(vector < vector < int >> & matrix){
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int >> & matrix){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
    }
    return rotated;
}

int main(){
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    vector < vector < int >> rotated = rotate(arr);
    cout << "rotated" endl;
    for(int i = 0; i < rotated.size(); i++){
        for(int j = 0; j < rotated.size(); j++){
            cout << rotated[i][j] << " ";
        }
    }
}
//Time Complexity: O(N*N);

// Optimal approach
void rotate(vector < vector < int >> & matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap([i][j], matrix[j][i]);
        }
    }
    // reversing the each row of matrix
    for(int i =0; i< n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector < vector < int >> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr); 
    cout << "rotated" << endl;
    for(int i =0; i  < arr.size(); i++){
        for(int j =0; j < arr[0].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Time complexity : O(N*N) + O(N*N).One O(N*N)































































































































