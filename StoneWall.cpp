// https://app.codility.com/demo/results/trainingND8F6R-2HV/

int solution(vector<int> &H) {
    if(!H.size()) return 0;
    
    stack<size_t> h;
    h.push(0);                                         // so that the stack is never empty
    h.push(H[0]);
    unsigned int res = 1, cur;
    for(unsigned int i=1;i<H.size();i++) {
        
        cur = H[i];
        // while : new < last item
        while( h.top()>cur) {h.pop();} // we need to remove all building blocks used for heights>cur

        // if same as last item
        if(h.top()==cur) {continue;} // we consider the prev block twice as wide() 
        else if( h.top()<cur) {
            h.push(cur);
            res++;
            continue;
            } // we add a block on top of the current base

    }
    return res;
}
