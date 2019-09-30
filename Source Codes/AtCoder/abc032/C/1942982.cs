using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var a = new int[n];
        var res = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(Console.ReadLine().Trim());
            if (a[i] == 0) { res = n; goto end; }
        }
        var s = 0; var t = 0; var m = 1L;
        while (true)
        {
            while (true)
            {
                m *= a[t++];
                if (m > k) { res = Math.Max(res, t - s - 1); break; }
                if (t == n) { res = Math.Max(res, t - s ); break; }
            }
            if (t == n) break;
            while (true)
            {
                m /= a[s++];
                if (m <= k | s == t) break;
            }
        }
        end:;
        Console.WriteLine(res);
    }
}