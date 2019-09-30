using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private const int MaxLength = 19;
    private int L;

    private bool Q(long n)
    {
        return Q(n.ToString());
    }

    private bool Q(string s)
    {
        Console.WriteLine("? {0}", s);
        return Console.ReadLine() == "Y";
    }

    public void Solve()
    {
        long p = 1;
        bool flag = true;
        for (int i = 1; i <= MaxLength; i++)
        {
            if (Q(p))
            {
                L = i;
            }
            else
            {
                flag = false;
                break;
            }
            p *= 10;
        }

        if (flag) //N = 10^k
        {
            long q = 2;
            for (int i = 1; i <= MaxLength; i++)
            {
                if (Q(q))
                {
                    Console.WriteLine("! {0}", q / 2);
                    return;
                }
                q *= 10;
            }
        }
        else
        {
            long max = p - 1;
            long min = p / 10;
            while (max - min > 1)
            {
                long mid = (max + min) / 2;
                if (Q(mid * 10))
                {
                    max = mid;
                }
                else
                {
                    min = mid;
                }
            }
            Console.WriteLine("! {0}", max);
            return;
        }
    }
}