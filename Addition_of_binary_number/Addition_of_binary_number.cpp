// sum = a xor b
// carry = ab
// OR
// sum = a xor b xor c
// carry = ab+bc+ca
#include <iostream>
#include <cstring> 

using namespace std;

string add(string a1, string b1)
{
    string sum, str1;
    int len, left, i;
    string a = string(a1.rbegin(), a1.rend());
    string b = string(b1.rbegin(), b1.rend());
    if(a.length()>b.length()){
        len=b.length();
        left=a.length();
        str1=a;
    }
    else{
        len=a.length();
        left=b.length();
        str1=b;
    }

    char c ='0';
    for(i = 0; i < len ; i++){
        sum += ((a[i] ^ b[i]) ^ c);
        c = ((a[i] & b[i]) | (a[i] & c)) | (b[i] & c);  //carry
        // cout << a[i] << " " << b[i] << " :: " << sum << " " << c << "\n";
    }

    for(i = len; i < left ; i++){
        sum += (str1[i] ^ c);
        c = str1[1] & c;  //carry
        // cout << a[i] << " " << b[i] << " :: " << sum << " " << c << "\n";
    }

    if(c=='1'){
        sum += c;
    }
    
    string res = string(sum.rbegin(), sum.rend());
    return res;
}

int main(){
    string a = "110";
    string b = "110";

    string res = add(a, b);
    cout << res;

    return 0;
}