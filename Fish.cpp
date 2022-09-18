// https://app.codility.com/demo/results/trainingDKGPQR-FPG/
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<stack>

int solution(vector<int> &strength, vector<int> &down) { // down 1 ,up 0
    stack<int> swimming_downhill;
    size_t res=0, n=strength.size();
    for (size_t i=0; i<n ;i++){
        if(down[i]) swimming_downhill.push(strength[i]); // if goes down - add to stack that represent fishs that go down.
        else if( swimming_downhill.empty()) res++; // fish goes upstream and nothing stops it
        else { // go upstraem against the fishes in the stack
            while(!swimming_downhill.empty() && strength[i]>swimming_downhill.top()) swimming_downhill.pop();
            if(swimming_downhill.empty()) res++;
            // else cur fish is weaker then its mortal enemy and join him (can't beat 'em)
        }
    }
    return res+swimming_downhill.size();
}
