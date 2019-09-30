using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var d = new int[m];
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine().Split(' ');
            for (int j = 1; j < s.Length; j++)
            {
                d[int.Parse(s[j]) - 1]++;
            }
        }

        var ans = 0;
        for (int i = 0; i < d.Length; i++)
        {
            if (d[i] == n) ans++;
        }
        Console.WriteLine(ans);
    }
}