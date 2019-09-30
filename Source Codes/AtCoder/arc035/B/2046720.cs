using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static long[] f = new long[10010];
    static void Main()
    {
        f[1] = 1;
        int n = int.Parse(Console.ReadLine());
        int[] a = Enumerable.Repeat(0, n).Select(_ => int.Parse(Console.ReadLine())).OrderBy(x => x).ToArray();
        long elapsed = 0;
        long score = 0;
        int last = a[0];
        List<int> dupliCount = new List<int>();
        dupliCount.Add(0);
        for (int i = 0; i < a.Length; i++)
        {
            if (last != a[i]) dupliCount.Add(1);
            else dupliCount[dupliCount.Count - 1]++;
            elapsed += a[i];
            score += elapsed;
            last = a[i];
        }
        Console.WriteLine(score);
        long res = 1;
        for (int i = 0; i < dupliCount.Count; i++)
        {
            res *= factorial(dupliCount[i]);
            res %= 1000000007;
        }
        Console.WriteLine(res);
    }
    static long factorial(int a) => f[a] != 0 ? f[a] : f[a] = (factorial(a - 1) * a) % 1000000007;
}