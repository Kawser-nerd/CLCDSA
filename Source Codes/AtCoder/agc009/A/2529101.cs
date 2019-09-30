using System;

public class Hello
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = new int[n];
        var b = new int[n];
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            a[i] = int.Parse(line[0]);
            b[i] = int.Parse(line[1]);
        }
        Array.Reverse(a); Array.Reverse(b);
        Console.WriteLine(getAns(a, b, n));
    }
    public static long getAns(int[] a, int[] b, int n)
    {
        var ret = 0L;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] + ret) % b[i] == 0) continue;
            ret += (b[i] - (a[i] + ret) % b[i]);
        }
        return ret;
    }
}