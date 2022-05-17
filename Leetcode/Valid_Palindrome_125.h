#pragma once
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
class ValidPalindrome {
public:
	bool isPalindrome(std::string& s) {
		int size = std::size(s);

		std::transform(s.begin(), s.end(), s.begin(), [&](unsigned char c)-> unsigned char{
			if (c > 64 && c < 91) {
				return std::tolower(c);
			}
			else if ((c > 96 && c < 123) || (c>47 && c<58)) {
				return c;
			}
			else {
				return ' ';
			}
		});
		s.erase(std::remove_if(s.begin(), s.end(), std::isspace), s.end());
		
		size = std::size(s);

		std::cout << s << ", " << size << std::endl;
		for (int i = 0; i < ceil(size / 2.0); i++) {
			if (s[i] != s[size - i -1]) {
				return false;
			}
		}
		return true;
	}

	bool isPalindrome2(std::string& s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
			while (!isalnum(s[i]) && i < j) i++; // Increment left pointer if not alphanumeric
			while (!isalnum(s[j]) && i < j) j--; // Decrement right pointer if no alphanumeric
			if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
		}

		return true;
	}
};

//amanaplanacanalpanama
//amanaplanacanalpanama