// https://app.codility.com/demo/results/trainingCUQWSP-W6U/
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> peaks;
    
    // get peaks
    for (int i=1; i<n-1 ; i++) {
        if(A[i]>A[i-1] && A[i]>A[i+1]) peaks.push_back(i);
    }

    n=peaks.size();
    if(!n) return 0;

    int count = 0,max = 0, last_peak=-40000000;
    int k = 1; // number of flags taken
    
    // incrementing the number of flags until there is no improvment OR k=number_of_peaks.
    while (k<=n) {
        for (auto i:peaks)  
            if(i-last_peak>=k && count<k){
                last_peak = i;            // correctness: we need to measure distance from the last placed flag, also the reason behind line 29.
                count++;
                }
        last_peak = -4000000;
        if(max>count) return max;
        max = count;
        k++;
        count=0;
    }

    return max;
}
