#include <iostream>
using namespace std;

int minDays(int S, int N, int M) {
    // Condition 1: cannot survive even one day
    if (M > N) return -1;

    // Condition 2: weekly survival check
    if (S >= 7 && (6 * N < 7 * M)) return -1;

    // Total food needed
    int totalFood = S * M;

    // Minimum days (ceil division)
    int days = (totalFood + N - 1) / N;

    return days;
}

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    cout << minDays(S, N, M);

    return 0;
}