#include<iostream>

using namespace std;


    string longestPalindrome(string s) {
        int maxlen = 1;
        int star = 0;
        bool f[1000][1000];
        for(int i = 0;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(i-j<2){
                    f[j][i]=(s[i]==s[j]);
                }
                else{
                    f[j][i]=(f[j+1][i-1]&&(s[i]==s[j]));
                }
                if(i-j>maxlen&&f[j][i]){
                    maxlen=i-j+1;
                    star=j;
                }
            }
        }
        return s.substr(star,maxlen);
        
    }

    int main(){
        string s;
        cout << "please input string： ";
        cin >> s;
        string ans;
        ans = longestPalindrome(s);
        cout <<"the answer is： "<< ans<< endl;;
        return 0; 
    }