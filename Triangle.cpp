
// things to note: the thing to note is the overflow.
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(),A.end());
    double temp;
    for(int i=2;i<A.size();i++){
        temp = (double)A[i-2]+(double)A[i-1];
        if (temp>A[i]) return true;
    }
    return false;
}
