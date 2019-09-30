using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var a = new int[n + 1];
        a[1] = int.Parse(Console.ReadLine().Trim());
        for (int i = 2; i <= n; i++)
        {
            var w = int.Parse(Console.ReadLine().Trim());
            a[i] = a[i - 1] + w;
        }
        Console.WriteLine(getAns(a, k));
    }
    public static int getAns(int[] a, int k)
    {
        var n = a.Length;
        for (int i = 3; i < n; i++)
            if (a[i] - a[i - 3] < k) return i;
        return -1;
    }
}