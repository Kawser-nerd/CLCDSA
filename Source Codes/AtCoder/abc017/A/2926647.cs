using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input1 = Console.ReadLine().Split(' ');
    int s1 = int.Parse(input1[0]);
    int e1 = int.Parse(input1[1]);
    int p1 = s1 * e1 / 10;
    
    string[] input2 = Console.ReadLine().Split(' ');
    int s2 = int.Parse(input2[0]);
    int e2 = int.Parse(input2[1]);
    int p2 = s2 * e2 / 10;
    
    string[] input3 = Console.ReadLine().Split(' ');
    int s3 = int.Parse(input3[0]);
    int e3 = int.Parse(input3[1]);
    int p3 = s3 * e3 / 10;
    
    Console.WriteLine(p1 + p2 + p3);
  }
}