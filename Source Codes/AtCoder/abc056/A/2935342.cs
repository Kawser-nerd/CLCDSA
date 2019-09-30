using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    string a = input[0];
    string b = input[1];
    
    if(a == b) Console.WriteLine("H");
    else Console.WriteLine("D");
  }
}