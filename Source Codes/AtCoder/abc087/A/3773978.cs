using System;
class A{
  static void Main()
  {
    var money = int.Parse(Console.ReadLine());
    var cake = int.Parse(Console.ReadLine());
    var donut = int.Parse(Console.ReadLine());
    Console.WriteLine((money-cake)%donut);
  }
}