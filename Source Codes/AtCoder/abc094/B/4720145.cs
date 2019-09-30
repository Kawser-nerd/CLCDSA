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
        int m = s[1];
        int x = s[2];

        var a = sc.intarr;

        int ans = 0;

        for (int i = 0; a[i] < x; ++i)
        {
            ans++;
        }
        wr.wri(Math.Max(0,Math.Min(ans, m - ans)));
        

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