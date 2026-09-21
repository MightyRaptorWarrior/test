#include <iostream>
using namespace std;
double doubleValue(double *a);
int main(){

    double a = 5;
    cout << doubleValue(&a) << endl;
}
double doubleValue(double *a){
    double value;
    value = *a;
    return value * 2;
}