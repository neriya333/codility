// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    if (A[n-1]<=0) return A[n-3]*A[n-2]*A[n-1];//all ng. e:
    if ((A[0]*A[1]>=A[n-3]*A[n-2]  || A[0]*A[1]>=A[n-1]*A[n-2]) && A[n-1]>0) return A[0]*A[1]*A[n-1]; // 2 great negative, 1 pos 
    return A[n-3]*A[n-2]*A[n-1]; // all pos.

    // write your code in C++14 (g++ 6.2.0)
    // edge: lots of neg and 0.                - multi by the 0
    //       2 great negative and all else pos - select 2 neg & pos
    //       all negative - select minimal number
    //       all positive
    //       one opistive
}
