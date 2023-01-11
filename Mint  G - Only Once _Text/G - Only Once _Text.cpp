//
//  main.cpp
//  Mint  G - Only Once _Text
//
//  Created by 山田啓太 on 2023/01/10.
//

/**
 AtCoder解説からの模範Solution
 Author  https://atcoder.jp/users/yuto1115
 For my TextBook
 */




//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint;

int main(){
    int n, m;
    cin >> n >> m;
    mint::set_mod(m);
    vector<mint> pow_n(n, 1);
    for(int i = 0; i < n - 1; i++){
        pow_n[i + 1] = pow_n[i] * n;
    }
    
    mint ans = 0;
    mint perm = 1;
    for(int l = 1; l <= n; l++){
        ans += perm * pow_n[n - l] * ((ll)l * (l-1) / 2);
        perm *= n - l;
    }
    ans *= n;
    cout << ans.val() << endl;
}

/**
 https://atcoder.jp/contests/abc284/tasks/abc284_g
 
 https://atcoder.jp/contests/abc284/tasks/abc284_g
 */



