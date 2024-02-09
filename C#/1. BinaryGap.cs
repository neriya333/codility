using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can write to stdout for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {
    public int solution(int N) {
        // Implement your solution here
        int maxima = 0, mask = 1, zeroCounter = 0, start = 0;
        while(N!=0){
            if((N & mask) != 0){
                if (start==1) maxima = Math.Max(maxima, zeroCounter);
                start = 1;
                zeroCounter = 0;
            }
            else
                zeroCounter++;
            N = N>>1;
        }
        return maxima;
    }
}
