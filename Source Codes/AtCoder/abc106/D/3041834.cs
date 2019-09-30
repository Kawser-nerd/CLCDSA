using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var q = int.Parse(line[2]);
        var a = new int[n, n];
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var wh = int.Parse(line[0]) - 1;
            var ww = int.Parse(line[1]) - 1;
            a[wh, ww]++;
        }
        var b = setArray(a);
        for (int i = 0; i < q; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var p = int.Parse(line[0]) - 1;
            var p2 = int.Parse(line[1]) - 1;
            Console.WriteLine(getAns(b, p, p2, n));
        }
    }
    public static int getAns(int[,] a, int p, int q, int n)
    {
        var a1 = 0; var a2 = 0; var a3 = 0; var a4 = 0;
        a1 = a[q, q];
        if (p - 1 >= 0) { a4 = a[p - 1, p - 1]; a2 = a[q, p - 1]; a3 = a[p - 1, q]; }
        return a1 - a2 - a3 + a4;
    }
    public static int[,] setArray(int[,] a)
    {
        var n = a.GetLength(0);
        var t = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            t[i, 0] = a[i, 0];
            for (int j = 1; j < n; j++)
                t[i, j] = t[i, j - 1] + a[i, j];
        }
        var t2 = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            t2[0, i] = t[0, i];
            for (int j = 1; j < n; j++)
                t2[j, i] = t2[j - 1, i] + t[j, i];
        }
        return t2;
    }
}