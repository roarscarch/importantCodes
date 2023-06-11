#include <bits/stdc++.h>
using namespace std;
void toLowerCase(string &s){
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch>='A' && ch<='Z'){
            ch=ch-'A'+'a';
            s[i]=ch;
        }
    }
} 
bool checkPalindrome(string s)
{
    toLowerCase(s);
    int i=0;
    int j=s.length()-1;
    if(isalnum(s[i]) == 0){
        ++i;
    }else if(isalnum(s[j])==0){
        --j;
    }else if(s[i]==s[j]){
        i++;
        j--;
    }else{
        return false;
    }
    return true;

}