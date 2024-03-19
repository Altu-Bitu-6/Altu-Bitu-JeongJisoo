#include <iostream>
#include <algorithm> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	int n;	
    cin >> n;
	string w,check; 
    cin >> w;

	int cnt = 0;
	int alp[26] = {0}; 
	int w_len = w.size();
    
	for (int i = 0; i < w_len; i++) { 
		alp[w[i] - 'A'] += 1;
	}
    
    for (int i = 0; i < n - 1; i++) {
		cin >> check;
		int check_len = check.size();
		int c[26];
		copy(alp, alp + 26, c); 

		int same = 0;
		for (int i = 0; i < check_len; i++) {
			if (c[check[i] - 'A'] > 0) {
				c[check[i] - 'A']--;
				same++;
			}
		}
		if (w_len == check_len) { 
			if (same == w_len || same == w_len - 1) {
				cnt++;
			}
		}else if (w_len + 1 == check_len && same == w_len){
            cnt++;
        }else if (w_len - 1 == check_len && same == w_len - 1){
            cnt++;
        }else continue; 
    }
    
	cout << cnt << '\n';	
}
