#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000000 + 10
#define lli long long int

lli min (lli x, lli y) {
    return x < y ? x : y;
}

int p[SIZE * 2 + 10];

string convertToNewString(string &s) {
    string w;
    w = "@";
    lli i;
    for( i = 0; i < s.size(); ++i) {
        w += ("#" + s.substr(i, 1));
    }
    w += "#$";
    return w;
}

lli manacharAlgorithm(string str) {
    string w = convertToNewString(str);

    /// Current Center and right
    lli center = 0, right = 0, iMirror, maxPalindrome, centerIndex, i;

    for (i = 1; i < w.size() - 1; ++i) {
        /// find the corresponding letter in the palindrome substring
        iMirror = center - (i - center);

        if (right > i) {
            p[i] = min(right - i, p[iMirror]);
        }

        /// Expanding around center i
        while (w[i - 1 - p[i]] == w[i + 1 + p[i]]) {
            p[i] += 1;
        }

        /// Update center, right case if the palindrome centered at i
        if (p[i] + i > right) {
            center = i;
            right = p[i] + i;
        }
    }
    maxPalindrome = 0;
    centerIndex = 0;

    for (i = 1; i < w.size() - 1; ++i) {
        if (p[i] > maxPalindrome) {
            maxPalindrome = p[i];
            centerIndex = i;
        }
    }

    //cout << str.substr((centerIndex - 1 - maxPalindrome) / 2, maxPalindrome) << '\n';

    return maxPalindrome;
}

int main() {
    lli n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    cout << manacharAlgorithm(s) << endl;

    return (0);
}
