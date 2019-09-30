using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



class Program
{
    const int MOD = 1000000007;
    const int INF = 1 << 30;

    static void Main(string[] args)
    {
        Solve();
    }

    static long GCD(long x,long y)
    {
        if (y == 0) return x;
        return GCD(y, x % y);
    }

    static long LCM(long x,long y)
    {
        return x * y / GCD(x, y);
    }

    static int keta(int x)
    {
        string s = x.ToString();
        return s[s.Length - 1]-'0';
    }

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();


        long ans = INF;
        var x = sc.intarr;
        int D = x[0];
        int G = x[1];
        long[] p = new long[D];
        long[] c = new long[D];
        for(int i = 0; i < D; ++i)
        {
            var y = sc.intarr;
            p[i] = y[0];
            c[i] = y[1];
        }

        for (int bit = 0; bit < (1 << D); ++ bit)
        {
            long sum = 0;
            long num = 0;

            for (int i = 0; i < D; ++i)
            {
                if ((bit & (1 << i)) != 0)
                {
                    sum += c[i] + p[i] * 100 * (i + 1);
                    num += p[i];
                }
                
            }
            if (sum >= G) ans = Math.Min(ans, num);
            else
            {
                for(int i = D - 1; i >= 0; --i)
                {
                    if ((bit& (1 << i)) != 0) continue;
                    for(int k = 0; k < p[i]; ++k)
                    {
                        if (sum >= G) break;
                        sum += 100 * (i + 1);
                        ++num;
                    }
                }
                ans = Math.Min(ans, num);
            }
        }
        wr.wri(ans);
        
    }


}
    




class Scan
{
        public string str => Console.ReadLine();

        public string[] strarr => str.Split(' ');

        public long[] longarr => strarr.Select(long.Parse).ToArray();
        public int[] intarr => strarr.Select(int.Parse).ToArray();
    public char[] chararr => str.ToArray();


}



class write
{
    public void wri<Type>(Type x)
    {
        Console.WriteLine(x);
    }
}