using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());
        int lcm = Lcm(a, b);
        int i = 0;
        while (lcm * i < n)
        {
            i++;
        }
        Console.WriteLine(lcm * i);
    }
    public static int Lcm(int a, int b)
    {
        return a * b / Gcd(a, b);
    }

    public static int Gcd(int a, int b)
    {
        if (a < b)
            return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}