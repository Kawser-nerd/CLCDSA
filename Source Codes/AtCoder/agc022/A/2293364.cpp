#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main(){

	std::string str;

	std::cin >> str;

	bool used_c[26] = {};

	if(str == "zyxwvutsrqponmlkjihgfedcba"){
		std::cout << -1 << std::endl;
		return 0;
	}

	std::vector<std::string> strs;
	if(str.length() == 26){
		for(int i = 0; i < 26; ++i){
			for(int j = 0; j < 26; ++j){
				if(!used_c[j] && str[i] - 'a' < j){
					strs.push_back(str.substr(0, i) + char('a' + j));
				}
			}
			used_c[str[i] - 'a'] = true;
		}
	}
	else{
		for(int i = 0; i < str.length(); ++i){
			used_c[str[i] - 'a'] = true;
		}
		for(int i = 0; i < 26; ++i){
			if(!used_c[i]){
				std::cout << str << char('a' + i) << std::endl;
				return 0;
			}
		}
	}

	std::sort(strs.begin(), strs.end());
	std::cout << strs[0] << std::endl;

	return 0;
}