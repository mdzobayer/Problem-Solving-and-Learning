#include <bits/stdc++.h>

using namespace std;
#define ll long long int
int n, k, m;

ll dp[55][55][3];

ll solve(int remainN, int remainK, bool flag) {
    if (remainK < 0 || remainN < 0) {
        return 0;
    }
    if (remainK == 0 && remainN == 0) {
        return 1;
    }

    if (dp[remainN][remainK][flag] != -1) {
        return dp[remainN][remainK][flag];
    }

    ll i, ans = 0;

    for (i = 1; i <= m; ++i) {
        ans += solve(remainN - i, remainK - 1, !flag);
    }

    return dp[remainN][remainK][flag] = ans;
}

int main() {

    //freopen("in.txt", "r", stdin);
    
    int test, t;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d", &n, &k, &m);

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %lld\n", t, solve(n, k, true));
    }


    return (0);
}