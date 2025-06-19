// This is a program to find the digits of an integer which can divide the integer itself.

#include <iostream>
#include <vector>
using namespace std;

int even_digit(int n){
    int counter = 0;
    int temp = n;
    while (n>0){
        // we extract last digit of the integer
        int lastDigit = n%10;
        cout<<lastDigit<<endl;
        if (temp % lastDigit==0) counter++; // if it divides the integer, we increment our counter

        n = n/10; // trim this number down
    }
    return counter;

};

int main(){
    int num = 22;
    int count = even_digit(num);
    cout<<"The number of digits that divide the number are: "<< count<<endl;
    
}