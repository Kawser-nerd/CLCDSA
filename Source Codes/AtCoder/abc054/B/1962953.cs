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
        int[] nums = SpRead(' ').Select(a => int.Parse(a)).ToArray();
        int N = nums[0];
        int M = nums[1];

        string[] s_1 = new string[N];
        string[] s_2 = new string[M];

        for (int i = 0; i < N; i++)
        {
            s_1[i] = Console.ReadLine();
        }
        for (int i = 0; i < M; i++)
        {
            s_2[i] = Console.ReadLine();
        }

        string s = "";

        for (int i = 0; i < (N - M) + 1; i++)
        {
            for (int j = 0; j < (N - M) + 1; j++)
            {
                s = s_1[i].Substring(j, M);
                if (s == s_2[0])
                {
                    for (int k = 0; k < M; k++)
                    {
                        s = s_1[i + k].Substring(j, M);
                        if (s != s_2[k]) break;
                        if (k + 1 == M) {
                            Console.WriteLine("Yes");
                            return;
                        }
                    }
                }
            }
        }
        Console.WriteLine("No");
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