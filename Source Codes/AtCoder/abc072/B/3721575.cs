using System;
using System.Text;
class Program
{
  static void Main(string[] args)
  {
    string input = Console.ReadLine();
    StringBuilder sb = new StringBuilder();
    for(var i = 0;i < input.Length; i++)
      if (i % 2 == 0) sb.Append(input[i]);
    Console.WriteLine(sb.ToString());
  }
}