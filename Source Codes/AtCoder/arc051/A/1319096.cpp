#include <iostream>

int X1, Y1, R;
int X2, Y2, X3, Y3;

bool inp(int x, int y){
    return (x-X1)*(x-X1) + (y-Y1)*(y-Y1) <= R*R;
}

int main(void){
    std::cin >> X1 >> Y1 >> R;
    std::cin >> X2 >> Y2 >> X3 >> Y3;

    if( X2 < X1 && X1 < X3 && Y2 < Y1 && Y1 < Y3 && X2 <= X1-R && X1+R <= X3 && Y2 <= Y1-R && Y1+R <= Y3 ){
        std::cout << "NO\n";
    }else{
        std::cout << "YES\n";
    }

    if(inp(X2,Y2) && inp(X2,Y3) && inp(X3,Y2) && inp(X3, Y3)){
        std::cout << "NO\n";
    }else{
        std::cout << "YES\n";
    }
}