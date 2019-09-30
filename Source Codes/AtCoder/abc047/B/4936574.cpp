#include <iostream>

int main()
{
    int rightw, righth, n;
    std::cin >> rightw >> righth >> n;
    int x[n],y[n],a[n];
    for(int i = 0; i < n; i++){
        std::cin >> x[i] >> y[i] >> a[i];
    }
    int leftw = 0, lefth = 0;
    for(int j = 0; j < n; j++){
        switch(a[j]){
            case 1:
                if(leftw < x[j]) 
                    leftw = x[j];
                break;
            case 2:
                if(rightw > x[j])
                    rightw = x[j];
                break;
            case 3:
                if(lefth < y[j])
                    lefth = y[j];
                break;
            case 4:
                if(righth > y[j])
                    righth = y[j];
                break;
        }
    }
    if(rightw > leftw && righth > lefth)
        std::cout << (rightw - leftw) * (righth - lefth);
    else
        std::cout << "0" << std::endl;
    return 0;
}