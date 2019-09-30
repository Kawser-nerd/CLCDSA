using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;

public class Hello
{

    public static void Main()
    {
        int[] n = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int min = n[1];
        int max = n[2];
        string[] s;
        int ans = 0;
        int box = 0;
        for (int i = 0; i < n[0]; i++) {
            s = Console.ReadLine().Split(' ');
            if (s[0] == "West")
            {
                if (int.Parse(s[1]) < min) box = -min;
                else if (max < int.Parse(s[1])) box = -max;
                else box = -int.Parse(s[1]);
            }
            else {
                if (int.Parse(s[1]) < min) box = min;
                else if (max < int.Parse(s[1])) box = max;
                else box = int.Parse(s[1]);
            }
            ans += box;
        }
        int f = Math.Sign(ans);
        if (ans == 0) Console.WriteLine(0);
        else if(f == -1) Console.WriteLine("West " + Math.Abs(ans));
        else Console.WriteLine("East " + Math.Abs(ans));
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

}