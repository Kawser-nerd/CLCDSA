using System.Linq;
using System.Collections.Generic;
using System;
class P{
  static void Main(){
    var x=Console.ReadLine().Split(' ').Select(int.Parse).ToList();
    var a=new List<int>();
    for(int i=0;i<5;i++)for(int f=0;f<5;f++)for(int g=0;g<5;g++)a.Add(i==f|f==g|g==i?0:x[i]+x[f]+x[g]);
    Console.WriteLine(a.Distinct().OrderBy(y=>-y).ToList()[2]);
  }
}