#pragma once
//https://www.lintcode.com/problem/659/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class EncodeDecodeString {
public:

	std::string encode(std::vector<std::string>& strs) {
		std::string result;
		for (auto str : strs) {
			addEscapeChar(str);
			result.append(str + sep);
		}
		result.resize(std::size(result) - 1);
		std::cout << result << std::endl;
		return result;
	}

	std::vector<std::string> decode(std::string& str) {
		size_t pos, lastPos = 0;
		std::vector<std::string> result;

		pos = str.find(sep);
		while (pos != std::string::npos) {
			if (str[pos - 1] == escape) {
				pos = str.find(sep, pos + 1);
			}
			else {
				appendString(result, str.substr(lastPos, pos - lastPos));
				lastPos = pos + 1;
				pos = str.find(sep, pos + 1);
			}
		}
		appendString(result, str.substr(lastPos, std::size(str)));
		return result;
	}

	void appendString(std::vector<string>& result, std::string subString) {
		removeEscaseChar(subString);
		result.push_back(subString);
	}

	void addEscapeChar(std::string& str) {
		size_t pos = str.find(sep);
		while (pos != std::string::npos) {
			str.insert(pos, 1, escape);
			pos = str.find(sep, pos + 2);
		}
	}

	void removeEscaseChar(std::string& str) {
		size_t pos = str.find(escape);
		while (pos != std::string::npos) {
			if (pos + 1 < std::size(str) && str[pos + 1] == sep) {
				str.erase(pos, 1);
				pos = str.find(escape, pos);
			}
			else {
				pos = str.find(escape, pos+1);
			}
		}
	}

	static const char escape = '\\';
	static const char sep =';';
};

