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

        var R = sc.intarr[0];
        if (R < 1200) wr.wri("ABC");
        else if (R < 2800) wr.wri("ARC");
        else wr.wri("AGC");
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