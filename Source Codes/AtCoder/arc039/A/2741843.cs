using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = int.Parse(line[0]);
        var b = int.Parse(line[1]);
        var r1 = a - getMin(b);
        var r2 = getMax(a) - b;
        Console.WriteLine(Math.Max(r1, r2));
    }
    public static int getMin(int n)
    {
        var a = new int[3];
        a[0] = n / 100;
        a[1] = (n / 10) % 10;
        a[2] = n % 10;
        if (a[0] != 1) a[0] = 1;
        else if (a[1] != 0) a[1] = 0;
        else a[2] = 0;
        return a[0] * 100 + a[1] * 10 + a[2];
    }
    public static int getMax(int n)
    {
        var a = new int[3];
        a[0] = n / 100;
        a[1] = (n / 10) % 10;
        a[2] = n % 10;
        if (a[0] != 9) a[0] = 9;
        else if (a[1] != 9) a[1] = 9;
        else a[2] = 9;
        return a[0] * 100 + a[1] * 10 + a[2];
    }
}