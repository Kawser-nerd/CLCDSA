using System;
using System.Collections.Generic;
public class P{
  static void Main(){
    int n=int.Parse(Console.ReadLine());
    var s=new List<int>{0,0,1};
    for(int i=3;i<n;i++)s.Add((s[i-1]+s[i-2]+s[i-3])%10007);
    Console.WriteLine(s[n-1]);
  }
}