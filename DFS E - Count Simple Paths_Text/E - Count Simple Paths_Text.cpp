//
//  main.cpp
//  E - Count Simple Paths_Text
//
//  Created by 山田啓太 on 2023/01/08.
//

/**
AtCoder　2023.01.17の解説からの模範解答
Author    https://atcoder.jp/users/Nyaan 

For my TextBook
*/


#include <iostream>
#include <vector>
using namespace std;

int calc(int N, vector<vector<int>> g){
    int ans = 0, limit = 1000000;
    vector<int> vis(N);
    auto dfs = [&](auto rc,int c) -> void {
        if(ans ==  limit) return;
        ans++;
        vis[c] = true;
        for(auto& d : g[c]){
            if(vis[d]) continue;
            rc(rc, d);
        }
        vis[c] = false;
    };
    dfs(dfs, 0);
    return ans;
}

int main(){
    cout << endl;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << calc(N, g) << endl;
    return 0;
}


/**
 
 https://atcoder.jp/contests/abc284/tasks/abc284_e
 
 https://atcoder.jp/contests/abc284/editorial/5494
 
 */





