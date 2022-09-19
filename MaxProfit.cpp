// https://app.codility.com/demo/results/trainingMKB489-53X/
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
    if(A.empty()) return 0;
    int m_gain = 0;
    int bought = A[0];

    for (auto i:A){
        if(i<bought) {bought = i; continue;}
        m_gain = max(m_gain,i-bought);
    }
    return m_gain;
    // write your code in C++14 (g++ 6.2.0)
}
