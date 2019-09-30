using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var N = int.Parse(Console.ReadLine());
        var str = Console.ReadLine().Split();
        var T = int.Parse(str[0]);
        var A = int.Parse(str[1]);
        var H = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var H2 = new double[N];
        for (int i=0; i<N; i++)
        {
            H2[i] = Math.Abs(A - (T - H[i]*0.006));
        }
        
        Console.WriteLine( Array.IndexOf(H2, H2.Min()) +1 );
    }
}