using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int md = (n % 2 == 0) ? n - 1 : n; //?????
        int me = (n % 2 == 0) ? n : n - 1; //?????
        List<int> b = new List<int>();
        for (int i = md; i > 0; i -= 2)
            b.Add(a[i - 1]);
        for (int i = 2; i <= me; i += 2)
            b.Add(a[i - 1]);
        int[] ans = b.ToArray();
        if (n % 2 == 0)
            Array.Reverse(ans);
        for (int i = 0; i < n - 1; i++)
            Console.Write("{0} ", ans[i]);
        Console.WriteLine(ans[n - 1]);
    }
}