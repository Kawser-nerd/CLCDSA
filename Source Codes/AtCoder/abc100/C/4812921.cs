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

    static int waru2(int x)
    {
        int ret = 0;
        while (x % 2 == 0)
        {
            x /= 2;
            ret++;
        }
        return ret;
    }


    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int N = sc.intarr[0];
        int[] a = sc.intarr;

        int ans = 0;
        foreach(var x in a)
        {
            ans += waru2(x);
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