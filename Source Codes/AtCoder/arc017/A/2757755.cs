using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        Console.WriteLine(IsPrime(n) ? "YES":"NO");
    }
    public static bool IsPrime(int n)
    {
        if (n < 2) return false;
        else if (n == 2) return true;
        else if (n % 2 == 0) return false;
        var sqrtNum = Math.Sqrt(n);
        for (int i = 3; i <= sqrtNum; i += 2)
            if (n % i == 0) return false;
        return true;
    }
}