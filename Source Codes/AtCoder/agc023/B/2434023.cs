using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var a = new char[n, n];
        for (int i = 0; i < n; i++)
        {
            var s =Console.ReadLine().Trim();
            for (int j = 0; j < n; j++) a[i, j] = s[j];
        }
        var count = 0;
        if (checkArray(a)) count++;
        for (int i = 0; i < n-1; i++)
        {
            getNew(a);
            if (checkArray(a)) count++;
        }
        Console.WriteLine(count * n);
    }
    public static void getNew (char[,] a)
    {
        var n = a.GetLength(0);
        var w = new char[n];
        for (int i = 0; i < n; i++)
            w[i] = a[i, n - 1];
        for (int i = 0; i < n; i++)
            for (int j = n - 2; j >= 0; j--) a[i, j+1] = a[i, j];
        for (int i = 0; i < n; i++)
            a[i, 0] = w[i];
    }
    public static bool checkArray (char[,] a)
    {
        var n = a.GetLength(0);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i, j] != a[j, i]) return false;
        return true;
    }
}