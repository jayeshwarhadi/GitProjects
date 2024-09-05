#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;

    int original = num;
    int rev = 0;
    while (num != 0)
    {
        rev = rev*10 + num%10;
        num /= 10;
    }
    if (rev==original)
    {
        cout << "Number is a Palintrome";
    }else
    {
        cout << "Number is not a Palintrome";
    }
}