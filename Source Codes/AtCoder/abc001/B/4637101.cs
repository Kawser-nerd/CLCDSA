using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    double x=double.Parse(Console.ReadLine());
    x/=1000;
    if(x<0.1)x=0;
    else if(x<=5)x*=10;
    else if(x<=30)x+=50;
    else if(x<=70)x=(x-30)/5+80;
    else x=89;
      Console.WriteLine(x.ToString("00"));
  }
}