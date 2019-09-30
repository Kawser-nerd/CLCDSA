using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var q = int.Parse(line[1]);
        var a = new int[n];
        for (int i = 0; i < q; i++)
        {
            string[] line2 = Console.ReadLine().Trim().Split(' ');
            var L = int.Parse(line2[0]) - 1;
            var r = int.Parse(line2[1]) - 1;
            a[L]++;
            if (r + 1 <= n - 1) a[r + 1]--;
        }
        Console.Write(a[0] % 2 == 0 ? 0 : 1);
        var pre = a[0];
        for (int i = 1; i < n; i++)
        {
            pre += a[i];
            Console.Write(pre % 2 == 0 ? 0 : 1);
        }
        Console.WriteLine();
    }
}