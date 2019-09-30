#include <iostream>
#include <string>
#include <map>

int main(){
	std::map<char, char> substitute_s, substitute_t;
	std::string s,t;

	std::cin >> s >> t;

	std::map<char,char>::const_iterator itr_s, itr_t;
	for( int len=s.length(), i=0; i<len; ++i ){
		itr_s = substitute_s.find(s[i]);
		if( itr_s != substitute_s.end() ){
			if( itr_s -> second != t[i] ){
				std::cout << "No" << std::endl;
				return 0;
			}
		}
		substitute_s.insert( std::make_pair( s[i], t[i] ));

		itr_t = substitute_t.find(t[i]);
		if( itr_t != substitute_t.end() ){
			if( itr_t -> second != s[i] ){
				std::cout << "No" << std::endl;
				return 0;
			}
		}
		substitute_t.insert( std::make_pair( t[i], s[i] ));
	}

	std::cout << "Yes" << std::endl;
}