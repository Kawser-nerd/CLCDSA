using System;
class Program
{
  static void Main()
  {
    int n = int.Parse(Console.ReadLine());
    n = 2025 - n;
    for(int i =1;i<10;i++)
    {
      if(n%i == 0)
      {
        int N = n/i;
        if(N<10)
        {
           Console.WriteLine(i +" "+ "x" +" "+ N);
        
        }
      }
    }
  }
}