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
        int m = Cin();
        int[] n = SpRead(' ').Select(a => int.Parse(a)).ToArray();
        if (n.Sum() % m != 0)
        {
            Console.WriteLine(-1);
            return;
        }
        int ave = n.Sum() / m;
        int box = 0;
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            if (ave < n[i])
            {
                //????
                if (0 < n[i] - ave)
                {
                    box += n[i] - ave;
                    if (box != 0) count++;
                }
            }
            else if (n[i] < ave)
            {
                //?????
                if (ave <= n[i] + box)
                {
                    //box?????????
                    box -= ave - n[i];
                    if (box != 0) count++;
                }
                else
                {
                    //???????????????
                    box -= ave - n[i];
                    if (box != 0) count++;
                }
            }
            else {
                if (box != 0) count++;
            }
            //Console.WriteLine("Box : " + box + " c : " + count);
        }
        Console.WriteLine(count);
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