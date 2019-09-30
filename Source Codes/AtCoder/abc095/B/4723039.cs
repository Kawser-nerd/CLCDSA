using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class Program
{


    static void Main(string[] args)
    {
        Solve();
    }

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        var s = sc.intarr;
        int n = s[0];
        int x = s[1];
        int sowa = 0;
        int mi = 1000000;
        for(int i = 0; i < n; ++i)
        {
            int m = sc.intarr[0];
            sowa += m;
            mi = Math.Min(mi, m);

        }

        wr.wri(n + (x - sowa) / mi);
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