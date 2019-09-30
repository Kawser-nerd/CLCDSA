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

        var k = sc.intarr;
        int a = k[0];
         k = sc.intarr;
        int b = k[0];
        k = sc.intarr;
        int c = k[0];
        k = sc.intarr;
        int d = k[0];


        wr.wri(Math.Min(a, b) + Math.Min(c, d));



    }


}
    class Scan
    {
        public string str => Console.ReadLine();

        public string[] strarr => str.Split(' ');

        public long[] longarr => strarr.Select(long.Parse).ToArray();
        public int[] intarr => strarr.Select(int.Parse).ToArray();
        public char[] chararr => strarr.Select(char.Parse).ToArray();


}



class write
{
    public void wri<Type>(Type x)
    {
        Console.WriteLine(x);
    }
}