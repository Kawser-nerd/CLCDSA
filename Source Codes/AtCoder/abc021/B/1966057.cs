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
        int N = Cin();
        int[] num = SpRead(' ').Select(m => int.Parse(m)).ToArray();
        int K = Cin();
        int[] city = SpRead(' ').Select(m => int.Parse(m)).ToArray();
        HashSet<int> hash = new HashSet<int>();
        hash.Add(num[0]);
        hash.Add(num[1]);
        for (int i = 0; i < K; i++) {
            if (hash.Contains(city[i]))
            {
                Console.WriteLine("NO");
                return;
            }
            else hash.Add(city[i]);
        }
        Console.WriteLine("YES");

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