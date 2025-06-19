#include <iostream>
#include <vector>
using namespace std;

int reverse(int n){
    int rev = 0;
    while(n>0){
        int lastDigit = n%10;
        rev = rev*10 + lastDigit;
        n = n/10;
        }
    return rev;
}

int main(){
    int num = 12300;
    int count = reverse(num);
    cout<<"reverse is: "<< count<<endl;

}

