// you can also use imports, for example:
// import java.util.*;

// https://app.codility.com/demo/results/training867KYX-BXR/

class Solution {
    public int solution(int N) {
        int mask = 1, maximum = 0, counter = 0;
        while(N != 0){
            if(N%2 == 0){ // reached 0
                if (counter > 0) counter++; // case: counting
                if (counter == -1) counter = 1;
            } 
            else { // reached 1
                if (counter == 0) counter=-1;
                else {
                    maximum = maximum>counter? maximum : counter;
                    counter = -1;
                } 
            }
            N = N>>1;
        }
        return maximum;
    }
}
