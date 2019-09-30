using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long ans = 0;
        var inp = new long[n][];
        for (int i = 0; i < n; i++)
            inp[i] = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        inp = inp.Reverse().ToArray();
        for (int i = 0; i < n; i++)
        {
            if ((inp[i][0] + ans) % inp[i][1] == 0) continue;
            ans += inp[i][1] - (inp[i][0] + ans) % inp[i][1];
        }
        Console.WriteLine(ans);
    }
}