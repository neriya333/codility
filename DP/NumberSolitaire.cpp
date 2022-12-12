// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// 
int max6(int a,int b,int c,int d,int e,int f){
    return max(max(a,b),max(max(c,d),max(e,f)));
}

int solution(vector<int> &A) {
    
    // special case. (*more about that below)
    for(int i = 1; i < min(6, (int)A.size()) ; i++){
        int maximal  = -10001;
        for(int k = i-1; k>=0 ; k--){
            if(A[k] > maximal) maximal = A[k];
        }
        A[i] += maximal;
    }

    for(int i = 6; i < A.size(); i++){
        A[i] += max6(A[i-1],A[i-2],A[i-3],A[i-4],A[i-5],A[i-6]);
    }

    return A[A.size()-1];
}

/** special case:
alternetivly we could include special case in the regular case using if, like this code:
I KNOW, ITS JAVA.
Java is greate as wel.
C'mon! don't make that face.  ;)

package NumberSolitaire;

class Solution {
    public int solution(int[] A) {

        // main idea:
        // using "dynamic programming" to build up the solution
        // (bottom up)
        
        int[] dp = new int[A.length];
        dp[0] = A[0];

        // build up from "dp[1], dp[2], ..., dp[A.length-1]"
        for(int i=1; i<A.length; i++){
            
            // keep the biggest one 
            // be very careful: could be negtive (so use Integer.MIN_VALUE)
            int max = Integer.MIN_VALUE;
            
            // a die could be "1 to 6" 
            for(int die=1; die<=6; die++){
                if( i-die >= 0){
                    // very important: not "A[i-die]+A[i]"
                    // instead, have to use "dp[i-die]+A[i]"
                    max = Math.max( dp[i-die]+A[i], max );
                    // dynamic programming:
                    // take the best:
                    // takeBest( dp[i-j] + value[j], curBest )
                }
            }    
            dp[i] = max; // keep the best one as the dp value    
        }
        
        return dp[A.length-1];
    }
}


*/
