using System;
using System.Collections.Generic;
class Program{
  static void Main(string[] args){
    string[] tmp=Console.ReadLine().Split(' ');
    int n=int.Parse(tmp[0]);
    int m=int.Parse(tmp[1]);
    string[] tmpx=Console.ReadLine().Split(' ');
    int[] x=new int[m];
    for(int i=0;i<m;i++){x[i]=int.Parse(tmpx[i]);}
    Array.Sort(x);
    int[] d=new int[m-1];
    for(int i=0;i<m-1;i++){d[i]=x[i+1]-x[i];}
    Array.Sort(d);
    int p=0;
    if(m>n){for(int i=0;i<m-n;i++){p+=d[i];}}
    Console.WriteLine(p);
  }
}