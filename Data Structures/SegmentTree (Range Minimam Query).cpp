#include <cstdio>
#include <cmath>
#include <climits>

/// Return minimum & maximum value
int minVal (int s, int y) {
    return s < y ? s : y;
}
int maxVal(int s, int y) {
    return s > y ? s : y;
}

/// Middle Index from corner index.
int getMid(int x, int y) {
    return x + (y - x) / 2;
}

int RMQUtil(int *st, int ss, int se, int qs, int qe, int si) {

    /// Node is a part of given range
    if (qs <= ss && qe >= se) {
        return st[si];
    }

    /// If query goes outside from index
    if (se < qs || ss > qe) return INT_MAX;

    /// Segment overlap with given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2 * si + 1),
                  RMQUtil(st, mid + 1, se, qs, qe, 2 * si + 2));

}

int RMQ(int *st, int n, int qs, int qe) {

    if (qs < 0 || qe > n - 1 | qs > qe) {
        return -1;  /// Invalid
    }
    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil (int arr[], int ss, int se, int *st, int si) {
    /// If there is one element
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    /// If there are more then one element
    int mid = getMid(ss, se);
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}
/// Allocate memory for segment tree
int *constructST(int arr[], int n){

    /// Height of segment tree
    int x = (int) (ceil(log2(n)));

    /// Maximum size of segment tree
    int max_size = 2 * (int) pow(2, x) - 1;

    /// Allocate memory
    int *st = new int[max_size];

    /// Fill the allocate memory st
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

int main() {

    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof (arr) / sizeof(arr[0]);

    /// Build segment tree
    int *st = constructST(arr, n);

    printf("Sum of values in given range = %d\n",
            RMQ(st, n, 1, 5));

    return (0);
}
