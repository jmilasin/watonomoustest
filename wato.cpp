// Copyright 2018 Jason Milasincic

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
using std::cout;
using std::endl;
using std::cin;

int checkValid() {
    int x;
    cin >> x;
    while (cin.fail()) {
        cin.clear();  // Clear the failbit
        cin.ignore(100, '\n');  // Flush the input stream
        cout << "Enter a number only between 0 and 10." << endl;;
        cin >> x;
    }
    return x;
}

int main(int argc, char *argv[]) {
    cout << "The computer has chosen a number from 0 to 10. " <<
        "Guess the number." << endl;

    // RNG setup
    std::random_device r;
    std::mt19937 rng(r());
    int numberToGuess = rng() % 10;
    int userGuess = 0;

    while (true) {
        // Ensure no junk input
        userGuess = checkValid();
        if (userGuess == numberToGuess) {
            cout << "You guessed the right number!" << endl;
            break;
        } else if (userGuess < 0 || userGuess > 10) {
            cout << "Your guess was outside the range of 0 to 10. " <<
                "Try again." << endl;
        } else {
            cout << "Wrong guess. Try again." << endl;
        }
    }
}
