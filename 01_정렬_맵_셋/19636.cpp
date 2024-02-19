#include <iostream>
#include <cmath>

using namespace std;

//
void yoyo(int w, int i0, int t, int day, int intake, int tdee){
    int w1, w2, i2;
    w1 = w;
    w2 = w;
    i2 = i0;
    
    for(int i=0; i<day; i++){
        w1 += intake - (i0 + tdee);
        w2 += intake - (i2 + tdee);
        if (abs(intake - (i2+tdee))>t){
            i2 += floor((intake-(i2+tdee))/2.0);
        }
    }
    if(w1<=0 || i0<=0) cout << "Danger Diet\n";
    else cout << w1 << " " << i0 << "\n";

    if(w2<=0 || i2 <=0) cout << "Danger Diet\n";
    else {
        cout << w2 << " " << i2 << " ";
        if(w+i0-(i2+0)>w) cout << "YOYO";
        else cout << "NO";
    }
}

int main(){
    int w, i0, t, day, intake, tdee;
    cin >> w >> i0 >> t;
    cin >> day >> intake >> tdee;
    
    yoyo(w, i0, t, day, intake, tdee);
    return 0;
}