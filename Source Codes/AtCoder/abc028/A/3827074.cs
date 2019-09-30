using System;
class A{
  static void Main(){
    var s = int.Parse(Console.ReadLine());
    var m = s == 100?"Perfect":s>=90?"Great":s>=60?"Good":"Bad";
    Console.WriteLine(m);
  }
}