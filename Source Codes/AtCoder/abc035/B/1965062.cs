using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{

    public static void Main()
    {
        char[] c = Console.ReadLine().ToCharArray();
        int n = Cin();
        int x = 0;
        int y = 0;
        int count = 0;
        for (int i = 0; i < c.Length; i++)
        {
            if (c[i] == 'R')
            {
                x += 1;
            }
            else if (c[i] == 'L')
            {
                x -= 1;
            }
            else if (c[i] == 'U')
            {
                y += 1;
            }
            else if (c[i] == 'D')
            {
                y -= 1;
            }
            else count++;
        }

        int ans = Math.Abs(x) + Math.Abs(y);
        if (n == 1) ans += count;
        else {
            for (int i = 0; i < count; i++) {
                if (ans <= 0)
                {
                    ans += 1;
                }
                else {
                    ans -= 1;
                }
            }
        }
        Console.WriteLine(ans);
    }
}



public class Atcoder
{
    static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static int LCM(int a, int b)
    {
        int c = a * b;
        if (a < b) Swap(ref a, ref b);
        int d = a % b;
        while (d != 0)
        {
            a = b;
            b = d;
            d = a % b;
        }
        return c / b;
    }
    public static string strReverce(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static int Cin()
    {
        return int.Parse(Console.ReadLine());
    }
    public static bool IsPrime(int n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        //double sqrtNum = Math.Sqrt(n);
        for (int i = 3; i < n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    public static string[] SpRead(char c)
    {
        return Console.ReadLine().Split(c);
    }
}