#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double ax,bx, cx, ay, by, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	
	double x=0-ax, y=0-ay, res;
	ax += x;
	bx += x;
	cx += x;
	ay += y;
	by += y;
	cy += y;
	res = abs(bx*cy-by*cx)/2.0;
	cout << fixed << res  << endl ;
	/*cout << "( " << ax << " , " << ay << " )" << endl;
	cout << "( " << bx << " , " << by << " )" << endl;
	cout << "( " << cx << " , " << cy << " )" << endl;
	*/
}