#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seeding a random number with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    cout << "WELCOME TO THE NUMBER GUESSING GAME!" << endl;

    do {
        cout << "\nGuess any random number between 1 and 100: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            cout << "Your guess is too high! Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Your guess is too low! Try again." << endl;
        } else {
            cout << "Congratulations! You have guessed the correct number " << randomNumber << " in " << attempts << " attempts." << endl;
        }
    }while (userGuess != randomNumber);
    
	return 0;
}
