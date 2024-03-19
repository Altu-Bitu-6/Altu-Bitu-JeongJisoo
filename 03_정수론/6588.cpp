#include <iostream>
#include <vector>

using namespace std;

vector<bool> Eratos(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX = 1000000;
    vector<bool> isPrime = Eratos(MAX);

    int n;
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }

        bool flag = false;
        for (int i = 3; i <= n; i += 2) {
            if (isPrime[i] && isPrime[n - i]) {
                flag = true;
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }
        if (!flag) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}
