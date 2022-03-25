#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return x;
        if(n<0){
            x=1.00000/x;
        }
        int b=abs(n);
        double a=x;
        while(b!=0){
            x=x*a;
            a=x;
            b--;
        }
        return x;
    }
};

//用vector的方法实现斐波那契数列
// class Solution {
// public:
//     int numWays(int n) {
//         vector<int> jump;
//         jump.push_back(1);
//         jump.push_back(1);
//         for(int i=2;i<=n;i++){
//             jump.push_back((jump[i-1]+jump[i-2])%1000000007);
//         }
//         return jump[n];
//     }
// };

int main(){
    Solution a;
    double x=2;
    int n=4;
    cout<<a.myPow(x,n)<<endl;
    return 0;
}