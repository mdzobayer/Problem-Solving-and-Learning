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
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(NULL);

///======================== Let's GO ========================

vector < vector < pair <int, int> > > graph[30010]

bool visited[30010];
LLI maxi, start, End;

int main() {
    //FastRead
    int x, y, w, test, t, n;

    cin >> test;
    for (t = 1; t <= test; ++t) {
        cin >> n;

        /// Reset Graph
        for (i = 0; i <= n + 1; ++i) {
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));

        for (i = 1; i < n; ++i) {
            cin >> x >> y >> w;
            graph[x].push_back(make_pair(y, w));
            graph[y].push_back(make_pair(x, w));
        }

        maxi = INT_MAX;
        visited[0] = 1;
        dfs(0,0);
        temps = start;
    }


    return (0);
}
