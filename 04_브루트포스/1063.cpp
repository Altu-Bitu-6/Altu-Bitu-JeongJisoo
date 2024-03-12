#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc;

cc move(string input, char x, char y){
    for(int i=0; i<input.size(); i++){
        char how = input[i]; 
        if(how == 'R'){
            x++; 
        }
        else if(how == 'L'){
            x--;
        }
        else if(how == 'B'){
            y--; 
        }
        else {
            y++;
        }
    }
    return {x,y}; 
}

bool range(cc position){
    if(position.first < 'A' || position.first > 'H' || position.second<'1' || position.second > '8'){
        return false;
    }
    return true;
}

bool isSame(cc k, cc s){
    return (k.first == s.first && k.second == s.second); 
}

int main(){
    cc k,s; 
    int n; 
    string input; 

    cin >> k.first >> k.second >> s.first >> s.second >> n;

    while(n--){
        cin >> input;

        cc next_k, next_s;

        next_k = move(input, k.first, k.second); 

        if(isSame(next_k,s)){
            next_s = move(input, s.first, s.second); 
        }
        else{
            next_s = s;
        }
        

        if(range(next_k) && range(next_s)){
            k = next_k;
            s = next_s;
        }
        
    }
    cout << k.first << k.second << "\n" << s.first << s.second;


    return 0;
}