using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int x = int.Parse(input[0]);
    int y = int.Parse(input[1]);
    
    if(x == 4 || x == 6 || x == 9 || x == 11) x = 1;
    else if(x == 2) x = 2;
    else x = 3;
    
    if(y == 4 || y == 6 || y == 9 || y == 11) y = 1;
    else if(y == 2) y = 2;
    else y = 3;
    
    if(x == y) Console.WriteLine("Yes");
    else Console.WriteLine("No");
  }
}