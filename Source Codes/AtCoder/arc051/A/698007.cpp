#include<iostream>
#include<cmath>
#include<string>

using namespace std;

double dist(double x1, double y1,
            double x2, double y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool is_in_circle(double x1,double y1,double r,
                  double x2,double y2,
                  double x3,double y3)
{
  if (dist(x1,y1,x2,y2)>r)return false;
  if (dist(x1,y1,x2,y3)>r)return false;
  if (dist(x1,y1,x3,y2)>r)return false;
  if (dist(x1,y1,x3,y3)>r)return false;
  return true;
}


int main()
{
  double x1,x2,x3,y1,y2,y3,r;
  cin >> x1 >> y1>> r;
  cin >> x2 >> y2 >> x3>> y3;
  string red="YES";
  string blue="YES";
  bool no_red=false;
  bool no_blue=false;
  if (r==0){ red = "NO"; no_red=true;}
  if (x2==x3 || y2==y3){ blue="NO"; no_blue=true;}
  if(no_red || no_blue) {cout << red << endl << blue << endl; return 0;}
  else
  {
    //double t = 1./sqrt(2);
    if(x1+r<=x3&&x1-r>=x2&&y1+r<=y3&&y1-r>=y2)
    {
      red = "NO";blue="YES";
      cout << red << endl << blue << endl;
    }
    //else if(x2>=x1-r*t&&x3<=x1+r*t&&y2>=y1-r*t&&y3<=y1+r*t)
    else if(is_in_circle(x1,y1,r,x2,y2,x3,y3))
    {
      red = "YES";blue="NO";
      cout << red << endl << blue << endl;
    }
    else
    {
      red = "YES";blue="YES";
      cout << red << endl << blue << endl;
    }

    return 0;
  }
}