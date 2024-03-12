#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int s = 0;
    while (n--) {
        string st;
        int x;
        cin >> st;

        if (st == "add") {
            cin >> x;
            s |= (1 << x);
        } else if (st == "remove") {
            cin >> x;
            s &= ~(1 << x);
        } else if (st == "check") {
            cin >> x;
            if(s & (1<<x)){
                cout <<"1\n";
            } else{
                cout <<"0\n";
            }
        } else if (st == "toggle") {
            cin >> x;
            if(s&(1<<x)){
                s &= ~(1<<x);
            }
            else{
                s |=(1<<x);
            }
        } else if (st == "all") {
            s = (1 << 21) - 1;
        } else if (st == "empty") {
            s = 0;
        }
    }

    return 0;
}
