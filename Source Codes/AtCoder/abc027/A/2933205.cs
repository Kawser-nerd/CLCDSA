using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int l1 = int.Parse(input[0]);
    int l2 = int.Parse(input[1]);
    int l3 = int.Parse(input[2]);
    
    if(l1 == l2) Console.WriteLine(l3);
    else if(l1 == l3) Console.WriteLine(l2);
    else if(l2 == l3) Console.WriteLine(l1);
  }
}