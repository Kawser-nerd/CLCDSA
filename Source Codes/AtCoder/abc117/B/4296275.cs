using System;
using System.Collections.Generic;
class Program{
  static void Main(string[] args){
    int n=int.Parse(Console.ReadLine());
    string[] tmp=Console.ReadLine().Split(' ');
    int[] l=new int[n];
    for(int i=0;i<n;i++){l[i]=int.Parse(tmp[i]);}
    Array.Sort(l);
    int s=0;
    for(int i=0;i<n-1;i++){s+=l[i];}
    Console.WriteLine(l[n-1]<s?"Yes":"No");
  }
}