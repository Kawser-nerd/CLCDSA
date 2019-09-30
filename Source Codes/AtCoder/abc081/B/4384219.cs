using System;
using System.Linq;

class Challenge
{
  static void Main()
  {
    var N = int.Parse(Console.ReadLine());
    var A = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
    
    int Count = 0;
    bool CanDivide = true;
    
    do
    {
      for (int j=0; j<N; j++)
      {
        if (A[j]%2 == 1) CanDivide=false;
        A[j] /= 2;
      }
      if (CanDivide) Count++;
    }while(CanDivide);
    Console.WriteLine(Count);
  }
}