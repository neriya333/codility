using System;
using System.Collections.Generic;

class Solution {
    public int solution(int[] A) {
        // Implement your solution here
        int min = 1;
        HashSet<int> hashSet = new HashSet<int>();
        foreach (int a in A) hashSet.Add(a);
        while (true) {
            if (hashSet.Contains(min)){
                min++;
            }
            else break;
        }
        return min;
    }
}
