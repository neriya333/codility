using System;
using System.Collections.Generic;

class Solution {
    public int solution(int[] A) {
        double minimal = (A[0]+A[1])/2.0, index = 0;
        for(int i = 0; i < A.Length - 2; i++){
            if(minimal > (A[i+1] + A[i])/2.0){
                minimal = (A[i+1]+A[i])/2.0;
                index = i;
            }
            if (minimal > (A[i+1]+A[i+2]+A[i])/3.0){
                minimal = (A[i+1]+A[i+2]+A[i])/3.0;
                index = i;
            }
        }
        if(minimal > (A[A.Length-2]+A[A.Length-1])/2.0){
            index = A.Length-2;
        }
        return (int)index;
    }
}
