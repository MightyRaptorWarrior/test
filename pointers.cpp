#include <iostream>
using namespace std;

void highestNumber(double numbers[]);
void lowestNumber(double numbers[]);
void updateMin(double *number, double curr);
void updateMax(double *number, double curr);
void getInput();
const int LIMIT_INPUT = 5;
double numbers[LIMIT_INPUT];



int main(){

    getInput();
    highestNumber(numbers);
    lowestNumber(numbers);

    return 0;
}
void getInput(){
    double input =0;
    for(int i=0; i < LIMIT_INPUT; i++){
        cout << "Enter a number: ";
        cin >> input;
        cout << '\n';
        numbers[i] = input;
    }
     
}

void highestNumber(double numbers[]){
    double num = numbers[0];
    for(int i=1; i<LIMIT_INPUT; i++){
        updateMax(&num, numbers[i]);
    }
    cout << "the highest number is : " << num << endl;
}
void lowestNumber(double numbers[]){
    double num = numbers[0];
    for(int i=1; i<LIMIT_INPUT; i++){
        updateMin(&num, numbers[i]);
    }
    cout << "the lowest number is : " << num << endl;
}
void updateMin(double *number, double curr){
    if(curr < *number){
        *number = curr;
    }
}
void updateMax(double *number, double curr){
    if(curr > *number){
        *number = curr;
    }
}
