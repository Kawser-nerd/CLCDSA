using System;
class A{
  static void Main()
  {
    var total = int.Parse(Console.ReadLine());
    var yenCount = int.Parse(Console.ReadLine());
    Console.WriteLine(total%500<=yenCount?"Yes":"No");
  }
}