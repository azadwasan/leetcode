#pragma once
#include <iostream>


//Disable implicit type conversion when accepting arguments for a function.
template <class T>
void myFunc(T) = delete; // C++11 

void myFunc(int x) {
	std::cout << x << std::endl;
}

//********************* 
class SlashingStones {};
SlashingStones slashStones{};//This is a normal object creation
SlashingStones slashStones2(); //This is a function declaration that returns SlashingStones object by value.

//********************************