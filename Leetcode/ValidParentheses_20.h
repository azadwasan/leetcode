//https://leetcode.com/problems/valid-parentheses/
#pragma once
#include <stack>
#include <string>

class ValidParentheses {
public:
	bool isValid(std::string s) {
		std::stack<char> parens{};
		for (auto c : s) {
			if (c == '{' || c == '[' ) {	//Convert {, [ and ( to their corresponding closing parenthesis }, ], )
				parens.push(c+2);			//For { and [ the corresponding parenthesis are two ascii codes away
			}
			else if (c == '(') {			//For (, it is just one ascii code away, hence add 1
				parens.push(c + 1);
			}
			else {
				if (parens.empty() || c != parens.top()) { //Now, simply check if the closing brackets are same as expected or if the stack is empty (hence no correponding parenthesis).
						return false;
				}
				parens.pop();
			}
		}
		return parens.empty();	//Check stack, if there are any elements still left, then there were incomplete pairs.
	}
};