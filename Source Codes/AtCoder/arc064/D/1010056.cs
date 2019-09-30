using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;

class Myon
{
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        //Console.SetOut(new Printer(Console.OpenStandardOutput()));
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }

    long mod = 1000000007;

    public void calc()
    {
        long N = cin.nextLong();
        long K = cin.nextLong();
        long ans = calc2(N, K);
        Console.WriteLine(ans);
    }

    /*
    List<long> prime;
    List<long> num;
    List<long> mul;
    int isPrime(long a)
    {
        long i;
        int ans = 1;
        for (i = 2; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                prime.Add(i);
                long cnt = 0;
                while(a%i == 0)
                {
                    cnt++;
                    a /= i;
                }
                num.Add(cnt);
                mul.Add(ans);
                ans *= (int)cnt + 1;
            }
        }
        if(a != 1)
        {
            prime.Add(a);
            num.Add(1);
            mul.Add(ans);
            ans *= 2;
        }
        return ans;
    }
    */
    
    long calc2(long N, long K)
    {
        List<long> num = new List<long>();
        for (int i = 1; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                num.Add(i);
                if (i != N / i) num.Add(N / i);
            }
        }
        num.Sort();

        int ID = num.Count;
        long[] dp = new long[ID];
        long ans = 0;
        for (int i = 0; i < ID; i++)
        {
            dp[i] = num[i];
            if (num[i] % 2 == 0) dp[i] /= 2;
        }
        
        for (int i = ID - 1; i >= 0; i--)
        {
            ans += calc3(num[i], K) * dp[i];
            ans %= mod;
            for (int j = 0; j < i; j++)
            {
                if(num[i] % num[j] == 0)
                {
                    dp[j] -= dp[i];
                    dp[j] %= mod;
                }
            }
        }

        ans %= mod;
        if (ans < 0) ans += mod;
        return ans;
    }

    long calc3(long N, long K)
    {
        N = (N + 1) / 2;
        return powmod(K, N);
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

class Printer : StreamWriter
{
    public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
    public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    public Printer(Stream stream, Encoding encoding) : base(stream, encoding) { }
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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

    public double nextDouble()
    {
        return double.Parse(next());
    }

}