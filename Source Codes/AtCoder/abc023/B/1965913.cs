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
        int n = Cin();
        string s = Console.ReadLine();
        if (n % 2 == 0)
        {
            Console.WriteLine("-1");
            return;
        }
        if (s == "b")
        {
            Console.WriteLine(0);
            return;
        }

        char next = '0';
        if (n % 3 == 0) next = 'a';
        else if (n % 3 == 1) next = 'b';
        else if (n % 3 == 2) next = 'c';
        string mirror = "";
        for (int i = 0; i < n; i++) {
            mirror += next.ToString();
            if (next == 'a') next = 'b';
            else if (next == 'b') next = 'c';
            else if (next == 'c') next = 'a';
        }
        if (mirror == s) Console.WriteLine((n - 1) / 2);
        else Console.WriteLine(-1);
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