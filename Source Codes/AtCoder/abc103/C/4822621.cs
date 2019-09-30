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
    

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int N = sc.intarr[0];
        var a = sc.longarr;

        long ans = 0;
        for(int i = 0; i < N; ++i)
        {
            ans += a[i] - 1;
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