#include <iostream>
#include <vector>
using namespace std;

vector <int> extract(int n){
    vector <int> v;
            
    while(n>0){
        int lastDigit = n%10;
        v.emplace_back(lastDigit);
        n = n/10;
        }
        return v;
    }

int main(){
    int n = 4321;
    vector <int> ans = extract(n);
    for(auto num: ans){
        cout<<"Digit: "<<num<<endl;
    }

}