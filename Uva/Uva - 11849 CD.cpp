#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

bool have[1000000000+5];

int main() {
    FastRead

    fRead("in.txt");

    ULL n, m, i, catalog, Count;
    while (cin >> n >> m) {
        if (n == 0 && n == 0) break;
        Count = 0;
        memset(have, 0, sizeof(have));

        for (i = 1; i <= n; ++i) {
            cin >> catalog;
            if (have[catalog]) {
                Count++;
            }
            else {
                have[catalog] = true;
            }
        }
        for (i = 1; i <= m; ++i) {
            cin >> catalog;
            if (have[catalog]) {
                Count++;
            }
            else {
                have[catalog] = true;
            }
        }
        cout << Count << endl;
    }

    return (0);
}
