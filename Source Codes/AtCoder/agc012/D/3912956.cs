using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;
    
    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int X = cin.nextInt();
        int Y = cin.nextInt();

        int[] c = new int[N];
        int[] w = new int[N];
        for (int i = 0; i < N; i++)
        {
            c[i] = cin.nextInt() - 1;
            w[i] = cin.nextInt();
        }

        int FirstMin = int.MaxValue / 2;
        int FirstColor = -1;
        int SecondMin = int.MaxValue / 2;
        int SecondColor = -1;

        for (int i = 0; i < N; i++)
        {
            if (FirstMin > w[i])
            {
                if (FirstColor != c[i])
                {
                    SecondColor = FirstColor;
                    SecondMin = FirstMin;
                }
                FirstMin = w[i];
                FirstColor = c[i];
            }
            else if(SecondMin > w[i] && FirstColor != c[i])
            {
                SecondMin = w[i];
                SecondColor = c[i];
            }
        }

        bool[] ok = new bool[N];
        int[] oknum = new int[N];
        int[] minimum = new int[N];

        for (int i = 0; i < N; i++)
        {
            if(c[i] != FirstColor)
            {
                if (w[i] + FirstMin <= Y)
                {
                    ok[i] = true;
                    oknum[c[i]]++;
                    if (minimum[c[i]] == 0 || minimum[c[i]] > w[i]) minimum[c[i]] = w[i];
                }
            }
            else
            {
                if (w[i] + SecondMin <= Y)
                {
                    ok[i] = true;
                    oknum[c[i]]++;
                    if (minimum[c[i]] == 0 || minimum[c[i]] > w[i]) minimum[c[i]] = w[i];
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (ok[i]) continue;
            if(minimum[c[i]] != 0 && minimum[c[i]] + w[i] <= X)
            {
                ok[i] = true;
                oknum[c[i]]++;
            }
        }

        setFact(N + 10);

        long ans = 1;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if(oknum[i] > 0)
            {
                ans *= revFact[oknum[i]];
                cnt += oknum[i];
                ans %= mod;
            }
        }

        ans *= fact[cnt];
        ans %= mod;

        Console.WriteLine(ans);
    }


    long mod = 1000000007;
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

    long[] fact; //??
    long[] revFact; //?????

    void setFact(int N)
    {
        fact = new long[N];
        revFact = new long[N];
        fact[0] = 1;
        for (int i = 1; i < N; i++)
        {
            fact[i] = fact[i - 1] * i;
            fact[i] %= mod;
        }
        revFact[N - 1] = powmod(fact[N - 1], mod - 2);
        for (int i = N - 2; i >= 0; i--)
        {
            revFact[i] = revFact[i + 1] * (i + 1);
            revFact[i] %= mod;
        }
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