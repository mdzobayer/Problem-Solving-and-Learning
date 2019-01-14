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
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

int main() {
    FastRead

    //fRead("in.txt");

    string s, t;
    bool flag;
    int i, j, Count;
    while(cin >> s) {
        cin.ignore();
        cin >> t;
        cin.ignore();

        flag = false;
        Count = s.size();
        for (i = 0; i < s.size(); ++i) {
            for (j = 0; j < t.size(); ++j) {
                if (i >= s.size()) break;

                if (s[i] == t[j]) {
                    --Count;
                    ++i;
                }
                if (Count == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }

    }


    return (0);
}
