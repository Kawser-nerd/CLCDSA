using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
    if(s[0]==1) s[0]+=13;
    if(s[1]==1) s[1]+=13;
    Console.WriteLine(s[0]==s[1]?"Draw":s[0]>s[1]?"Alice":"Bob");
  }
}