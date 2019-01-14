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

//int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
//                  {0,-1,1,0,-1,1,1,-1}};

//int knight[2][8] = {{-2,-2,-1,1,2,2,1,-1},
//                    {-1,1,2,2,1,-1,-2,-2}};
//bool sevenSegment[8][10] =
//{
//    {0,0,0,0,0,0,0,0,0,0}, ///Segment 0
//    {1,0,1,1,0,1,1,1,1,1}, ///Segment 1
//    {1,1,1,1,1,0,0,1,1,1}, ///Segment 2
//    {1,1,0,1,1,1,1,1,1,1}, ///Segment 3
//    {1,0,1,1,0,1,1,0,1,1}, ///Segment 4
//    {1,0,1,0,0,0,1,0,1,0}, ///Segment 5
//    {1,0,0,0,1,1,1,0,1,1}, ///Segment 6
//    {0,0,1,1,1,1,1,0,1,1}  ///Segment 7
//};
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

const int MAX = 1e5+10;

int neg[MAX], zero[MAX], arr[MAX], n, k;

void update(int i, int v, int arr []) {
    while(i <= n) {
        arr[i] += v;
        i += i & (-i);
    }
}
int getSum(int i, int arr[]) {
    int result = 0;
    while(i > 0) {
        result += arr[i];
        i -= i & (-i);
    }
    return result;
}

int main() {

    FastRead
    //fRead("in.txt");

    int x, y, i, res;
    string str;

    while(cin >> n >> k) {
        memset(neg, 0, sizeof(neg));
        memset(zero, 0, sizeof(zero));
        for (i = 1; i <= n; ++i) {
            cin >> x;
            if (x < 0) update(i, 1, neg);
            else if(x == 0) update(i, 1, zero);
            arr[i] = x;
        }
        for (i = 0; i < k; ++i) {
            cin.ignore();
            cin >> str >> x >> y;
            //cout << str << " " << x << " " << y << endl;
            if(str[0] == 'C') {
                if (y == 0) {
                    if (arr[x] == 0)
                        continue;
                    update(x, 1, zero);
                    if(arr[x] < 0)
                        update(x, -1, neg);
                    arr[x] = y;
                    continue;
                }
                else {
                    if (arr[x] == 0)
                        update(x, -1, zero);
                    if (y < 0 && arr[x] >= 0)
                        update(x, 1, neg);
                    if  (y > 0 && arr[x] < 0)
                        update(x, -1, neg);
                    arr[x] = y;
                }
            }
            else {
                res = getSum(y, zero) - getSum(x-1, zero);
                char ch;
                if (res) ch = '0';
                else {
                    res = getSum(y, neg) - getSum(x-1, neg);
                    if (res & 1)
                        ch = '-';
                    else
                        ch = '+';
                }
                putchar(ch);
            }
        }
        putchar('\n');
    }

    return (0);
}
