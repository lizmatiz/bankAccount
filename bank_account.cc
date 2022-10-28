/**
 * @file bank_account.cc
 * @author Elizabeth Hooton (eh151720@ohio.edu)
 * @brief project 2
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// includes the libraries we need
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>


using namespace std;

int main() {

// makes everything fixed so setprecision works
cout.setf(ios::fixed);

// declaring variables
double balance = 2300;
const int PIN = 3579;
int menu_input = 0;
string menu_input_string = "0";
char menu_input_char = 'a';
int pin_input = 0;
int pin_attempts = 0;
double deposit_input = 0.0;
double withdraw_input = 0.0;
bool quit = false;

// do while loop that prints the menu, accepts user input, and either prints out the balance,
// asks for a pin, accepts a deposit, or accepts a withdraw based on the input with a switch statement
do{

cout << endl << "1 - see balance" << endl << "2 - deposit" << endl << "3 - withdraw" << endl <<  "4 - quit" << endl << endl;


cin >> menu_input_string;
menu_input_char = menu_input_string[0];
if(menu_input_string.length() == 1){
    if(isdigit(menu_input_char)){
        menu_input = std::stoi(menu_input_string);
    }
    else{
        menu_input = 5;
    }
}
else{
    menu_input = 5;
}

// switch statement
switch (menu_input){

// if the input is 1
case 1:

// prints out the balance
cout << "Balance: $" << setprecision(2) << balance << endl;
break;


// if the input is 2
case 2:

// if the pin attempts are greater than or equal to three, print a statement
if (pin_attempts >= 3){
    cout << "Too many attempts, your account has been locked!";
}

// if the pin attempts are below 3, a pin can be entered
else {
    cout << "enter the pin: " << endl;
    cin >> pin_input;

// checks if the pin is correct, if it is, you can make a deposit. after, it prints your balance.
    if (pin_input == PIN){
        cout << "How much would you like to deposit?" << endl;
        cin >> deposit_input;
        balance = balance + deposit_input;
        cout << "This is your balance: $" << setprecision(2) << balance << endl;
    }

// else the pin is incorrect, so the pin attempts are incremented by 1, there is also a print statement to tell the user
    else {
        pin_attempts++;
        cout << "Incorrect pin" << endl;
    }

    }
break;


// if the input is 3
case 3:

// if the pin attempts are greater than or equal to three, print a statement
if (pin_attempts >= 3){
    cout << "Too many attempts, your account has been locked!";
}

// if the pin attempts are below 3, a pin can be entered
else {

    cout << "enter the pin: " << endl;
    cin >> pin_input;

// checks if the pin is correct. if so, you can attempt to withdraw
    if (pin_input == PIN){
        cout << "How much would you like to withdraw?" << endl;
        cin >> withdraw_input;

// if the withdraw amount is less than or equal to the balance, you can withdraw. the new balance is printed.
        if (withdraw_input <= balance){
            balance = balance - withdraw_input;
            cout << "This is your balance: $" << setprecision(2) << balance << endl;
        }

// if the withdraw amount is more than the balance, it prints a statement that tells the user they don't have enough money.
        else {
            cout << "Insufficient funds" << endl;
        }

    }

// if the pin attempt is incorrect, it increments the attempt variable and prints that the pin is incorrect
    else {
        pin_attempts++;
        cout << "Incorrect pin" << endl;
    }

    }
break;

// turns the variable quit to true, will break the loop
case 4:
quit = true;
break;


// default statement if none of the inputs are correct
default:
cout << "Please enter a valid option." << endl;
break;

}

/* while statement that says the loop continues if the user does not want to quit and if the 
attempts for the pin are less than 3 */
} while (quit == false && pin_attempts < 3);

// if the user inputted 4, it prints a goodbye statement
if (menu_input == 4){
    cout << "Thanks for updating your account! Goodbye.";
}

// if the user made three or more attempts to enter the pin, it sends a shutting down message
if (pin_attempts >=3){
    cout << "Too many incorrect pin attempts, shutting down.";
}


return 0;
}
