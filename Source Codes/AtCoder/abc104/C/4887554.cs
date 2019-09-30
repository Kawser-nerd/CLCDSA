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

    //static long GCD(long x,long y)
    //{
    //    if (y == 0) return x;
    //    return GCD(y, x % y);
    //}

    //static long LCM(long x,long y)
    //{
    //    return x * y / GCD(x, y);
    //}

    //static int keta(int x)
    //{
    //    string s = x.ToString();
    //    return s[s.Length - 1]-'0';
    //}

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();


        long ans = INF;
        var x = sc.longarr;
        int D = (int)x[0];
        long G = x[1];
        long[] p = new long[D];
        long[] c = new long[D];

        for(int i = 0; i < D; ++i)
        {
            var y = sc.longarr;
            p[i] = y[0];
            c[i] = y[1];
        }

        for (int i = 0; i < (1 << D); ++ i)
        {
            long sum = 0;
            long num = 0;

            for (int j = 0; j < D; ++j)
            {
                if (((i>>j)&1) == 1)
                {
                    sum += c[j] + p[j] * 100 * (j + 1);
                    num += p[j];
                }
                
            }
            if (sum >= G) ans = Math.Min(ans, num);
            else
            {
                for(int j = D - 1; j >= 0; --j)
                {
                    if (((i>>j)&1) == 1) continue;

                    for(int k = 0; k < p[j]; ++k)
                    {
                        if (sum >= G) break;

                        sum += 100 * (j + 1);
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