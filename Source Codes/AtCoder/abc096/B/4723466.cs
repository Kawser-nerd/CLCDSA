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
        int a = s[0];
        int b = s[1];
        int c = s[2];
        int k = sc.intarr[0];

        wr.wri(a + b + c - Math.Max(Math.Max(a, b), c) + Math.Max(Math.Max(a, b), c) * Math.Pow(2, k));
            
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