// https://app.codility.com/demo/results/training7NBSVF-VNX/
// by Neriya Cohen

#include <stack>

int solution(string &s) {
    stack<char> copels;
    char top_item = 15;
    for(char i:s){
        if (i=='{' || i=='(' || i=='['){ copels.push(i); }
        else { 
            if (copels.empty()) {return false;}
            top_item = copels.top();
            copels.pop();
            if(top_item!='|' && top_item!='\\' && abs(top_item-i)>2) return false;  // ascii thing
            }
    }
    bool ret;
    copels.empty()? ret = true: ret = false;
    return ret;
}
