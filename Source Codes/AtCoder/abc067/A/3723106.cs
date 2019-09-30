using System;
class P{
  static void Main(){
    var s=Console.ReadLine().Split();
    int a=int.Parse(s[0]),b=int.Parse(s[1]);
    Console.WriteLine((a%3==0)|(b%3==0)|((a+b)%3==0)?"Possible":"Impossible");
  }
}