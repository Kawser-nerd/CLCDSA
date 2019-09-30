using System;
using System.Collections.Generic;
using System.Linq;
//using System.Threading.Tasks;
//using System.Numerics;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    void init()
    {

    }

    long mod = 1000002013;
    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            int n = cin.nextInt();
            long p = cin.nextLong();
            long all = 1L << n;
            long mina = 0;
            long maxa = 1L << n;
            while (maxa - mina > 1)
            {
                long mid = (maxa + mina) / 2;
                if (getworstplace(mid, all) >= p) maxa = mid;
                else mina = mid;
            }

            long minb = 0;
            long maxb = 1L << n;
            while (maxb - minb > 1)
            {
                long mid = (maxb + minb) / 2;
                if (getbestplace(mid, all) >= p) maxb = mid;
                else minb = mid;
            }

            Console.WriteLine(mina + " " + minb);
        }

    }

    long getbestplace(long a, long nokori)
    {
        long ret = 0;
        while (nokori != 1)
        {
            ret <<= 1;
            if (a != nokori - 1)
            {
                a = (a + 1) / 2;
            }
            else{
                ret++;
                a -= nokori / 2;
            }
            nokori >>= 1;
        }

        return ret;
    }

    long getworstplace(long a, long nokori)
    {
        long ret = 0;
        while (nokori != 1)
        {
            if (nokori == 0) break;
            ret <<= 1;
            if (a != 0)
            {
                a = (a - 1) / 2;
                ret++;
            }
            nokori >>= 1;
        }
        //Console.WriteLine(ret);
        return ret;
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
    } 

    long getnum(int n)
    {
        return ((long)n * (n - 1) / 2) % mod;
    }

}




class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }
}