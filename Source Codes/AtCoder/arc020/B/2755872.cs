using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var c = int.Parse(line[1]);
        var a = new int[n];
        var ret = int.MaxValue;
        for (int i = 0; i < n; i++) a[i] = int.Parse(Console.ReadLine().Trim());
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++)
                if (i != j)
                {
                    var count = 0;
                    var p = 0;
                    while (true)
                    {
                        if (a[p++] != i) count++;
                        if (p == n) break;
                        if (a[p++] != j) count++;
                        if (p == n) break;
                    }
                    ret = Math.Min(ret, count);
                }
        Console.WriteLine(ret * c);
    }
}