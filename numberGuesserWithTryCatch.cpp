// Copyright(c) 2022 Feyi Akomolafe All rights reserved.
//
// Created by : Feyi Akomolafe
// Created on : November 2022
// ICS3U-Unit4-04.cpp File, learning break statement in C++.

#include <iostream>
#include <random>
#include <string>

int main() {
    // creating variables
    std::string inputNumber;
    float inputNumberAsFloat;
    int initialNumber;
    int randomNumber;
    int inputNumberAsInt;

    // random generator
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);

    // input
    std::cout << "Guess the number from 0 to 9: ";
    std::cin >> inputNumber;

    // process and output
    std::cout << "\n";
    try {
        initialNumber = std::stoi(inputNumber);
        inputNumberAsInt = std::stoi(inputNumber);
        inputNumberAsFloat = std::stof(inputNumber);
        while (true) {
            if (inputNumberAsInt < 0 || inputNumberAsInt > 9) {
                std::cout << "Please input a number between 0 and 9.";
                break;
            } else if (inputNumberAsFloat != initialNumber) {
                std::cout << "Please input a whole number.";
                break;
            } else if (inputNumberAsInt == randomNumber) {
                std::cout << "You guessed right.";
                break;
            }
            std::cout << "You guessed wrong, Please try again: ";
            std::cin >> inputNumber;
            inputNumberAsInt = std::stoi(inputNumber);
        }
    } catch (std::invalid_argument) {
        std::cout << "\ninvalid input, "
                  << inputNumber << " does not fit the requirements.";
        std::cout << "\nPlease try again "
                  << "and input a whole number between 0 and 9";
    }

    std::cout << "\n\n\nDone.\n";
}
