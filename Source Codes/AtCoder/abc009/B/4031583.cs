using System;
using System.Collections.Generic;
using System.Linq;
class P{
  static void Main(){
    int n=int.Parse(Console.ReadLine());
    var s=new List<int>();
    for(int i=0;i<n;i++)s.Add(int.Parse(Console.ReadLine()));
    Console.WriteLine(s.OrderBy(x=>-x).Distinct().ToList()[1]);
  }
}