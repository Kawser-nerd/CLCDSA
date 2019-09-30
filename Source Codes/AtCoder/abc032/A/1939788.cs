using System;

public class Hello
{
    public static void Main()
    {
        var a = int.Parse(Console.ReadLine().Trim());
        var b = int.Parse(Console.ReadLine().Trim());
        var n = int.Parse(Console.ReadLine().Trim());
        var ab = Lcm(a, b);
        var r = (n + ab - 1) / ab;
        Console.WriteLine(r * ab);
    }
    public static int Lcm(int a, int b)
    {
        if (a < b) return Lcm(b, a);
        var ab = a * b;
        while (b != 0)
        {
            var wk = a % b;
            a = b;
            b = wk;
        }
        return ab / a;
    }
}