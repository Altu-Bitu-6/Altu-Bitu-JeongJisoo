#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            p.push(num);
            if (p.size() > N) {
                p.pop();
            }
        }
    }
    cout << p.top();
}
