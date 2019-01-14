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

    int p1, p2, p3, p4, angle, temp;
    while(cin >> p1 >> p2 >> p3 >> p4) {
        if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0) {
            break;
        }
        /// Each number is 9 degrees, of course (360/40 = 9)
        /// 3 Full turns is 360 * 3 = 1080
        angle = 1080;
        temp = p1 - p2;
        if (temp < 0) temp += 40;
        angle += (temp * 9);

        temp = p3 - p2;
        if (temp < 0) temp += 40;
        angle += (temp * 9);

        temp = p3 - p4;
        if (temp < 0) temp += 40;
        angle += (temp * 9);

        cout << angle << endl;
    }

    return (0);
}
