using System;
using System.Linq;

class Challenge
{
    static void Main()
    {
        var N = int.Parse(Console.ReadLine());
      	if (N == 1) { Console.WriteLine("1"); return; }

      	var count_N = new int[N+1];
        for (int i=1; i<=N; i++)
        {
            var x = i;
            var count = 0;
            while(x%2 == 0)
            {
                x /= 2;
                count++;
            }
            count_N[i] = count;
        }
      
        Console.WriteLine( Array.IndexOf(count_N, count_N.Max()) );
    }
}