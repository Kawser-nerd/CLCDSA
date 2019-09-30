using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        if (n == 1) { Console.WriteLine("Not Prime");  goto end; }
        var t1 = isNotDev3(n);
        var t2 = isNot1Even(n);
        var t3 = isPrime(n);
        Console.WriteLine((!t3 &&   t1 && t2) | t3 ? "Prime" : "Not Prime");
        end:;
    }
    public static bool isNotDev3(int n)
    {
        var s = n.ToString();
        var res = 0;
        for (int i = 0; i < s.Length; i++)
            res += int.Parse(s[i].ToString());
        return res % 3 != 0;
    }
    public static bool isNot1Even(int n)
    {
        var w = n % 10;
        return (w != 5 && w % 2 != 0);
    }
    public static bool isPrime(int n)
    {
        if (n < 2) return false;
        else if (n == 2) return true;
        else if (n % 2 == 0) return false;
        double sqrtNum = Math.Sqrt(n);
        for (int i = 3; i <= sqrtNum; i += 2)
            if (n % i == 0) return false;
        return true;
    }
}