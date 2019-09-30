using System;

class Program
{
    static void Main(string[] args)
    {
        var nk = Console.ReadLine().Split(' ');
        var n = int.Parse(nk[0]);
        var k = int.Parse(nk[1]);
        var l = new int[n];

        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            l[i] = int.Parse(s[i]);
        }

        Array.Sort(l, (x, y) => y - x);

        var ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += l[i];
        }

        Console.WriteLine(ans);
    }
}