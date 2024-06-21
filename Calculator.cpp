#include<iostream>
using namespace std;

int main(){
    double num1,num2;
    char operation;

    cout<<"Welcome to a Simple Calculator"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"Enter the First Number: "<<endl;
    cin>>num1;
    cout<<"Enter the Second number: "<<endl;
    cin>>num2;

    cout<<"Which operation do you want to perform(+,-,*,/): "<<endl;
    cin>>operation;

    switch(operation){
        case '+':
        cout<<"Result: "<<num1 + num2 <<endl;
        break;
        case '-':
        cout<<"Result: "<<num1 - num2 <<endl;
        break;
        case '*':
        cout<<"Result: "<<num1 * num2 <<endl;
        break;
        case '/':
        if(num2 != 0){
            cout<<"Result: "<< num1 / num2<<endl;
        }
        else{
            cout<<"Error: Division by zero!...."<<endl;
        }
        break;
        default:
        cout<<"Error: Invalid operation!...."<<endl;
        break;
    }
    return 0;
}