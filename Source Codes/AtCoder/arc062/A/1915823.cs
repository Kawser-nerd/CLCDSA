using System; 
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int[][] TA = new int[N][].Select(_ => Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray()).ToArray();

        long T = TA[0][0];
        long A = TA[0][1];
        int t;
        int a;
        foreach (int[] ta in TA)
        {
            t = ta[0];
            a = ta[1];

            long n = Convert.ToInt64(Math.Max(A / a + (A % a != 0 ? 1 : 0), T / t + (T % t != 0 ? 1 : 0)));
            T = t * n;
            A = a * n;
        }
        Console.WriteLine(T + A);
    }
}