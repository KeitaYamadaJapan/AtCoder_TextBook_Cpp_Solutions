//
//  main.cpp
//  F - ABCBAC_Text
//
//  Created by 山田啓太 on 2023/01/09.
//

/**
 AtCoder 2023.01.17の解説からの模範Solution
 Author      https://atcoder.jp/users/yuto1115
 For my Text
 */

#include <iostream>
#include<vector>
//#include<atcoder/string>

/**
 <atcoder/string>
 https://github.com/atcoder/ac-library/blob/master/atcoder/string.hpp */

using namespace std;
//using namespace atcoder;

template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

int main() {
    cout << endl;
    int n;
    cin >> n;
    string t;
    cin >> t;
    
    string a = t.substr(0, n);
    string b = t.substr(n);
    reverse(b.begin(), b.end());
    
    string x = a + b;
    vector<int> za_x = z_algorithm(x);
    za_x.push_back(0);
    
    string y = b + a;
    vector<int> za_y = z_algorithm(y);
    za_y.push_back(0);
    
    for (int i = 0; i <= n; i++) {
        if(za_x[2 * n - i] < i) continue;
        if(za_y[n + i] < n - i) continue;
        cout << t.substr(0, i) + t.substr(n + i) << endl;
        cout << i << endl;
        return 0;
    }
    
    cout << -1 << endl;
}

/**
 https://atcoder.jp/contests/abc284/tasks/abc284_f
 
 https://atcoder.jp/contests/abc284/editorial/5469
 */



