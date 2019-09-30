using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var a = new char[n, n];
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine().Trim();
            for (int j = 0; j < n; j++)
                a[j, n - 1 - i] = s[j];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (j != n - 1) Console.Write(a[i, j]);
                else Console.WriteLine(a[i, j]);
    }
}