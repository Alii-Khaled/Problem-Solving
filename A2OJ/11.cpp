#include <iostream>
#include<cmath>
bool isPrime(int num);
int nextPrime(int num);

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    if (nextPrime(n) == m) cout << "YES";
    else    cout<< "NO";

    return 0;
}
bool isPrime(int num){
    for(int i=2; i <= sqrt(float(num)); i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}


int nextPrime(int num){
    for(num++; !isPrime(num); num++);
    return num;
}
