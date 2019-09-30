#include <iostream>
#include <string>

const char table[] = "yhesocvxduiglbkrztnwjpfmaq";

int main(void) {
    int num_cases;
    std::cin >> num_cases;
    std::string s;
    std::getline(std::cin, s);

    for (int casenum = 1; casenum <= num_cases; ++casenum) {
	std::getline(std::cin, s);

	for (int i = 0, e = s.size(); i < e; ++i) {
	    if (isalpha(s[i])) {
		// A non-portable dependency on the ASCII character set!!!
		s[i] = table[s[i] - 'a'];
	    }
	}

	std::cout << "Case #" << casenum << ": " << s << "\n";
    }
}
