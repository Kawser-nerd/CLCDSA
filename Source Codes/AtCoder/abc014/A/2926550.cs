using System;

class Program
{
  static void Main(string[] args)
  {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int amari = a % b;
    
    if(amari == 0)
    {
      Console.WriteLine("0");
    }
    else{
      Console.WriteLine(b - amari);
    }
  }
}