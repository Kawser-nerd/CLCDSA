using System;

class Program
{
  static void Main(string[] args)
  {
    int a = int.Parse(Console.ReadLine());
    int ansa = 0;
    for(int i = 1; i < a; i++){
      int x = i;
      int y = a - i;
      if(ansa < x * y)
      {
        ansa = x * y;
      }
    }
    Console.WriteLine(ansa);
  }
}