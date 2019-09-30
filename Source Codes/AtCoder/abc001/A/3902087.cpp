#include<iostream>
using namespace std;
class sekisetu {
public:
	int h1, h2;
	void nyuuryoku();
	void keisan();
};
void sekisetu::nyuuryoku() {
	cin >> h1;
	cin >> h2;
};
void sekisetu::keisan() {
	cout << h1 - h2<<"\n";
}; 
int main() {
	sekisetu obj;
	obj.nyuuryoku();
	obj.keisan();
	return 0;
};