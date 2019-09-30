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
        int[] num = SpRead(' ').Select(n => int.Parse(n)).ToArray();
        List<int> list = new List<int>();
        for (int a = 0; a < 5; a++)
        {
            for (int b = a + 1; b < 5; b++)
            {
                for (int c = b + 1; c < 5; c++)
                {
                    if (!list.Contains(num[a] + num[b] + num[c])) list.Add(num[a] + num[b] + num[c]);
                }
            }
        }
        list.Sort();
        list.Reverse();
        Console.WriteLine(list[2]);
        
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