// https://app.codility.com/demo/results/trainingJB26HQ-AYM/
// CodeCheck Report: trainingJB26HQ-AYM



int solution(vector<int> &A) {
    int acc = A[0], cur_max = A[0], n = A.size(), item;
    if(n == 1) return A[0];

    for(int i = 1; i < n; i++){
        item = A[i];
        if(item >=0 ) acc = max(acc + item, item);
        else{
            if(cur_max < acc) cur_max = acc;
            acc = max(acc + item, item);
        }
    }
    return max(acc, cur_max);
}
/* 
accum = cur_max = A[0]
for each item
     - if it increases acc => acc = max(acc+num, num) // in case acc was negative we need to max
     - if it decrease acc => if cur_max < acc => curr_ max = acc.acc = acc = max(acc+num, num)
     return max(acc,cur)


*/
