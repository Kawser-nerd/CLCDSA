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

        var s = sc.longarr;

        long a = s[0];
        long b = s[1];
        long k = s[2];

        for (long i = a; i <= Math.Min(a + k - 1, b); i++)
        {
            wr.wri(i);
        }
        for(long i = Math.Max(b-k+1, Math.Min(a + k - 1, b)+1); i <= b; ++i)
        {
            wr.wri(i);
        }

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