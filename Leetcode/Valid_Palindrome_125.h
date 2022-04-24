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
			else if (c > 96 && c < 123) {
				return c;
			}
			else { 
				return ' ';
			}
		});
		s.erase(std::remove_if(s.begin(), s.end(), std::isspace), s.end());
		size = std::size(s);
		for (int i = 0; i < ceil(size / 2.0); i++) {
			if (s[i] != s[size - i -1]) {
				return false;
			}
		}
		return true;
	}
};

//amanaplanacanalpanama
//amanaplanacanalpanama