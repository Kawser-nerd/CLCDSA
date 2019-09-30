using System;
using System.Linq;
class Program
{
    static int GCM(int n, int m)
    {
        if (Math.Min(n, m) == 0)
            return Math.Max(n, m);
        if (Math.Max(n, m) % Math.Min(n, m) == 0)
            return Math.Min(n, m);
        return GCM(Math.Max(n, m) - Math.Min(n, m), Math.Min(n, m));
    }
    static void Main()
    {
        int[] a;
        int n, k;
        a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        n = a[0];
        k = a[1];
        a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int m = a.Max();
        int gcm = a[0];
        for (int i = 0; i < n; i++)
            gcm = GCM(gcm, a[i]);
        if (k % gcm == 0 && k <= m)
        {
            Console.WriteLine("POSSIBLE");
            Environment.Exit(0);
        }
        Console.WriteLine("IMPOSSIBLE");
    }
}