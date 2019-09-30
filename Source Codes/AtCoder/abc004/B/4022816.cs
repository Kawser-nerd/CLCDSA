using System;
using System.Linq;
class P{
  static void Main(){
    var a="";
    for(int i=0;i<4;i++)a=new string(Console.ReadLine().Reverse().ToArray())+"\n"+a;
    Console.WriteLine(a);
  }
}