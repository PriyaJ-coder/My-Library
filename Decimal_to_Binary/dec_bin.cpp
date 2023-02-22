#include<iostream>
using namespace std;

int dec_bin(long dec, long res, long i){
    // long res=0;
    if(dec==0){
        return res;
    }
    res=res+i*(dec%2);
    // cout << dec;
    // cout << res;
    return dec_bin(dec/2, res, i*10);
}

int main(){
    long dec;
    cin >> dec;
    cout << dec_bin(dec, 0, 1);
    return 1;
}