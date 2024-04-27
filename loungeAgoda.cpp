#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    vector<int> v(n) ;
    unordered_map<int,int> mp1 ;
    unordered_map<int,int> mp2 ;
    int mx1 = INT_MIN ;
    int mx2 = INT_MIN ;
    for (int i = 0 ; i < n ; i++){
        cin>>v[i] ;
        mp1[v[i]]++ ;
        mx1 = max(mx1 , v[i]) ;
    }
    
    int n2 ;
    cin>>n2 ;
    vector<int> supp(n2) ;
    for (int i = 0 ; i < n2 ; i++){
        cin>>supp[i] ;
        mp2[supp[i]]++ ;
        mx2 = max(mx2 , supp[i]) ;
    }
    
    int demand ;
    cin>>demand ;
    
    vector<int> suf1(mx1+1) ;
    vector<int> suf2(mx2+1) ;
    
    suf1[mx1] = mp1[mx1] ;
    suf2[mx2] = mp2[mx2] ;
    
    for (int i = mx1-1 ; i >= 0 ; i--){
        if (mp1.find(i) != mp1.end()){
            suf1[i] = suf1[i+1] + mp1[i] ;
        }
        else {
            suf1[i] = suf1[i+1] ;
        }
    }
    
    for (int i = mx2-1 ; i >= 0 ; i--){
        if (mp2.find(i) != mp2.end()){
            suf2[i] = suf2[i+1] + mp2[i] ;
        }
        else {
            suf1[i] = suf1[i+1] ;
        }
    }
    
    int ans = 0 ;
    
    for (int i = 0 ; i < suf1.size() ; i++){
        int t = (suf1.size()-i)*demand ;
        if (suf1[i] < t){
            ans += (t-suf1[i]) ;
        }
    }
    
    for (int i = mx1+1 ; i < suf2.size() ; i++){
        if (suf2[i] >= demand){
            ans += demand ;
        }
        else {
            ans += suf2[i] ;
            break ;
        }
    }
    
    cout<<ans<<endl ;
    

    return 0;
}
