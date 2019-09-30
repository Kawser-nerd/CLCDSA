using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }


    Scanner cin;

    long mod = 1000000007;

    void calc()
    {
        cin = new Scanner();
        int S = cin.nextInt();
        int sum = 0;
        long ans = 0;
        int start = 1;
        int add = 0;
        int target = 1;
        int dec = 1;
        int targetd = 10;
        for (int end = 1; start < 1e8; end++)
        {
            if(end == target)
            {
                add++;
                target *= 10;
            }
            sum += add;
            while(sum > S)
            {
                sum -= dec;
                start++;
                if (start == targetd)
                {
                    dec++;
                    targetd *= 10;
                }
            }
            if (sum == S && start < 1e8) ans++;
        }
        ans %= mod;

        for (int i = 1; i * i <= S; i++)
        {
            int k = i;
            int kk = S / i;
            if (k * kk != S) continue;
            if (k >= 9) {
                ans += (9 * powmod(10, k - 1)) - (S / k - 1);
                ans %= mod;
            }
            if (k == kk) continue;
            k = kk;

            if (k >= 9)
            {
                ans += (9 * powmod(10, k - 1)) - (S / k - 1);
                ans %= mod;
            }
        }

        /*
        for (int k = 9; k <= S; k++)
        {
            if(S % k == 0)
            {
                ans += (nowNum - (S / k - 1));
                ans %= mod;
            }
            nowNum *= 10;
            nowNum %= mod;
        }
        */

        for (int k = 1; k <= S; k++)
        {
            int div = S / k;
            if (div < 9) break;
            if (div * k == S) continue;
            ans++;
        }


        ans += mod;
        ans %= mod;
        Console.WriteLine(ans);
    }

    
    long powmod(long a, long p)
    {
        long ans = 1;
        long mul = a;
        for (; p > 0; p >>= 1, mul = (mul * mul) % mod)
        {
            if ((p & 1) == 1) ans = (ans * mul) % mod;
        }
        return ans;
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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}