// https://app.codility.com/demo/results/training39WYH8-Y2G/
#include <stack>

int get_leader(vector<int> &A);

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int NO_LEADER = 1000000001;

int solution(vector<int> &A) {
    int a_leader = get_leader(A);
    // cout<<a_leader<<endl;
    if(a_leader==NO_LEADER) return 0;
    
    int counter = 0;
    int lhs_c_leader=0, rhs_c_leader=0;
    for(auto j:A) if(j==a_leader) rhs_c_leader++;

    size_t n = A.size();
    
    for(size_t i=0;i<n-1;i++){
        if(A[i]==a_leader) {
            lhs_c_leader++;
            rhs_c_leader--;
        }
        
        bool legit = lhs_c_leader>(i+1)/2.0 && rhs_c_leader>(n-i-1)/2.0;
        // cout<<lhs_c_leader<<" "<<(i+1)/2.0<<" "<<rhs_c_leader<<" "<<(n-i-1)/2.0;
        // cout<<lhs_c_leader<<" "<<(i+1)/2.0<<" legit:"<<legit<<endl;
        // cout<<i<<" lhs:"<<lhs_c_leader<<" rhs:"<< rhs_c_leader<<" res:"<<legit<<endl; 
        if(legit) counter++;
    }

    return counter;
}

int get_leader(vector<int> &A){
    stack<int> s;
    for (auto i:A) {
        if(s.empty() || s.top()==i) s.push(i);
        else s.pop(); // s not empty and with a different item then i
    }
    size_t c=0;
    if(s.empty()) return NO_LEADER;
    for(auto i:A) if (i==s.top()) c++;
    if(c > (float)A.size()/2) return s.top();
    return NO_LEADER;
}
