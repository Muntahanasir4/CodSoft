#include <iostream>

using namespace std;

int main() {
    char operate;
    
    cout << "WELCOME TO THE BASIC ARITHMETIC CALCULATOR!" << endl;

    // Taking an operator as input from the user
    cout << "Choose an operator ['+', '-', '*', '/']: ";
    cin >> operate;
    
    // Taking two numbers as input from the user for further calculations
    int num1, num2;
    cout << "Enter any number: ";
    cin >> num1;
    cout << "Enter any number: ";
    cin >> num2;
    
    int result;
    switch (operate) {
        case '+':
            result = num1 + num2;
            break;
        
        case '-':
            result = num1 - num2;
            break;
        
        case '*':
            result = num1 * num2;
            break;
        
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Division by zero is not allowed!" << endl;
                return 1; // Exit the program with an error code
            }
            break;
        
        default:
            cout << "Sorry! You have chosen an invalid operator." << endl;
            return 1; // Exit the program with an error code
    }
    
    cout << num1<<" "<< operate<<" "<< num2 << " = " << result << endl;
	return 0;
}
