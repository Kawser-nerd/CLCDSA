using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        Array.Sort(a);
        int c = 1;
        int[] b = new int[n + 1];
        b[0] = 0;
        if (n > 1)
        {
            for (int i = 0; i < a.Length - 1; i++)
            {
                if (a[i] != a[i + 1])
                {
                    b[c] = i;
                    c++;
                }
            }
        }
        b[c] = a.Length;
        int ans = 0;
        if (c > 2)
            for (int i = 0; i < c; i++)
                ans += b[i + 1] - b[i] - 1;
        Console.WriteLine(ans);
    }
}