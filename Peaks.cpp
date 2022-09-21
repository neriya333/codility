// https://app.codility.com/demo/results/trainingK9TPEM-MMA/
// somthing is not right. Where are you sneaky little bug, hm?

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> peaks,div;
    // get the peak indeices
    for(int i=1;i<n-1;i++) if ( A[i+1]<A[i] && A[i-1]<A[i]) peaks.push_back(i);

    if(!peaks.size()) return 0;

    int n_div = 1, jump_size = n, prev, max = 1, n_peaks=peaks.size();
    while(true){
        prev=0;
        n_div++;
        jump_size = n/n_div;
        if(n_div>n_peaks) break;
        if(n%n_div!=0) continue; // in case div to eq part is not possible or div to more then peaks.

        // run over the peaks and make sure there is a peak for each part in the partition
        for(int p:peaks){
            if(p>prev && p<=jump_size+prev) prev+=jump_size;
            else if(p>jump_size+prev) break; // this means that there is no peak in range (prev,jump_size+prev] . we still need to check some more though
        }

        if(prev >= n) max = n_div;
    }
    return max;
}
