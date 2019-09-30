using System;
class P{
  static void Main(){
    var s=int.Parse(Console.ReadLine());
    if(s%400==0)Console.WriteLine("YES");
    else if(s%100==0)Console.WriteLine("NO");
    else if(s%4==0)Console.WriteLine("YES");
    else Console.WriteLine("NO");
  }
}