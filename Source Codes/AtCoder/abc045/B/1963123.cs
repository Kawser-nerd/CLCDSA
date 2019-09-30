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
        char[] A = Console.ReadLine().ToCharArray();
        char[] B = Console.ReadLine().ToCharArray();
        char[] C = Console.ReadLine().ToCharArray();
        int turn = (A.Length + B.Length + C.Length);
        int a_t = 0;
        int b_t = 0;
        int c_t = 0;
        char next = 'a';
        for (int i = 0; i < turn; i++)
        {
            if (i + 1 == turn)
            {
                if (next == 'a') Console.WriteLine("A");
                else if (next == 'b') Console.WriteLine("B");
                else if (next == 'c') Console.WriteLine("C");
                return;
            }

            if (next == 'a')
            {
                if (a_t == A.Length) {
                    Console.WriteLine("A");
                    return;
                }
                next = A[a_t];
                a_t++;
            }
            else if (next == 'b')
            {
                if (b_t == B.Length)
                {
                    Console.WriteLine("B");
                    return;
                }
                next = B[b_t];
                b_t++;
            }
            else if (next == 'c')
            {
                if (c_t == C.Length)
                {
                    Console.WriteLine("C");
                    return;
                }
                next = C[c_t];
                c_t++;
            }
        }
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