#include <iostream>
#include <cmath>

int main()
{
	int  I, O, T, J, L, S, Z;
	std::cin >> I >> O >> T >> J >> L >> S >> Z;
	uint64_t res = 0;
	res += (I/2)*4/2;
	res += O*2/2;
	res += (J/2)*4/2;
	res += (L/2)*4/2;
	if((I>0 && J>0 && L>0)
	 && ((I %2)+(J %2)+(L %2) >= 2)){
		res += 6/2;
		if((I %2)+(J %2)+(L %2) >= 3){
		}
		else{
			res -= 4/2;
		}
	}
	std::cout << res << std::endl;
}