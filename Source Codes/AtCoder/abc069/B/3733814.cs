using System;

class Program
{
  static void Main(string[] args)
  {
    string str = Console.ReadLine();
    
    Console.WriteLine(str[0] + (str.Length - 2).ToString() + str[str.Length - 1]);
  }
}