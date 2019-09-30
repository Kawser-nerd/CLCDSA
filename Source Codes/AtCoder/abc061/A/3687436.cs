using System;
class P{
  static void Main(){
    var s=Console.ReadLine().Split();
    Console.WriteLine(int.Parse(s[2])>=int.Parse(s[0])&int.Parse(s[2])<=int.Parse(s[1])?"Yes":"No");
  }
}