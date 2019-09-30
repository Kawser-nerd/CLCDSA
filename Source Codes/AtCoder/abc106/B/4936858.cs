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



    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        var N = sc.intarr[0];
        if (N <= 104) wr.wri(0);
        else if (N <= 134) wr.wri(1);
        else if (N <= 164) wr.wri(2);
        else if (N <= 188) wr.wri(3);
        else if (N <= 194) wr.wri(4);
        else wr.wri(5);

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