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

        var t = sc.intarr;
        int a = t[0];
        int b = t[1];
        int c = t[2];
        int d = t[3];

        if (Math.Abs(a - c) <= d || (Math.Abs(a - b) <= d && Math.Abs(b - c) <= d))
        {
            wr.wri("Yes");
        }
        else wr.wri("No");


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