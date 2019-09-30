using System;
using System.Linq;
using System.Collections.Generic;
public class c
{
  public static void Main()
  {
    int n=int.Parse(Console.ReadLine());
    long m=0;
    long a=0;
    long r=0;
    long c=0;
    long h=0;
    for(int i=0;i<n;i++)
    {
      string s=Console.ReadLine();
      if(s[0]=='M')m++;
      else if(s[0]=='A')a++;
      else if(s[0]=='R')r++;
      else if(s[0]=='C')c++;
      else if(s[0]=='H')h++;
    }
    long ans=m*a*r;
    ans+=m*a*c;
    ans+=m*a*h;
    ans+=m*r*c;
    ans+=m*r*h;
    ans+=m*c*h;
    ans+=a*r*c;
    ans+=a*r*h;
    ans+=a*c*h;
    ans+=r*c*h;
    Console.WriteLine(ans);
  }
}