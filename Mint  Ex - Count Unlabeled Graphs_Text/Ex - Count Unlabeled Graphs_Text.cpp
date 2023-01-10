//
//  main.cpp
//  Mint  Ex - Count Unlabeled Graphs_Text
//
//  Created by 山田啓太 on 2023/01/10.
//

/**
 AtCoder 2023.01.07の開設からの模範Solution
 Author   https://atcoder.jp/users/Nyaan
 For my textBook
 */

#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
#include "atcoder/modint.hpp"
using mint = atcoder::modint;

struct Binomial {
    vector<mint> fac, invfac, inv;
    Binomial(int n) : fac(n + 1), invfac(n + 1), inv(n + 1) {
        fac[0] = invfac[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
        invfac[n] = fac[n].inv();
        for (int i = n - 1; i >= 0; i--) {
            invfac[i] = invfac[i + 1] * (i + 1);
            inv[i + 1] = invfac[i + 1] * fac[i];
        }
    }
    mint operator()(int n, int r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fac[n] * invfac[n - r] * invfac[r];
    }
};

mint inner_calc(int N, int K) {
    Binomial C{100};
    mint ans = 0;
    vector<pair<int, int>> v;
    auto dfs = [&](auto rc, int n, int last) -> void {
        if (n == 0) {
            mint cur = 1;
            for (int i = 0; i < (int)v.size(); i++) {
                auto [cyc1, num1] = v[i];
                cur /= C.fac[num1] * (mint{cyc1}.pow(num1));
                cur *= mint{K}.pow(num1);
                cur *= mint{2}.pow(cyc1 / 2 * num1);
                cur *= mint{2}.pow(cyc1 * num1 * (num1 - 1) / 2);
                for (int j = 0; j < i; j++) {
                    auto [cyc2, num2] = v[j];
                    cur *= mint{2}.pow(gcd(cyc1, cyc2) * num1 * num2);
                }
            }
            ans += cur;
            return;
        }
        for (int nxt = last + 1; nxt <= n; nxt++) {
            for (int i = 1; nxt * i <= n; i++) {
                v.emplace_back(nxt, i);
                rc(rc, n - nxt * i, nxt);
                v.pop_back();
            }
        }
    };
    dfs(dfs, N, 0);
    return ans;
}

int main() {
    int N, K, mod;
    cin >> N >> K >> mod;
    mint::set_mod(mod);

    Binomial C{100};
    mint ans = 0;
    for (int k = 1; k <= K; k++) {
        ans += inner_calc(N, k) * C(K, k) * (k % 2 == K % 2 ? 1 : -1);
    }
    cout << ans.val() << endl;
}

/**
 https://atcoder.jp/contests/abc284/tasks/abc284_h
 
 https://atcoder.jp/contests/abc284/editorial/5481
 */
