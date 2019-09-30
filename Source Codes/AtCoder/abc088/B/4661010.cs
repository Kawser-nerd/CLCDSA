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

        var p1 = sc.longarr;
        long n = p1[0];
        var a = sc.longarr;

        Array.Sort(a);
        Array.Reverse(a);
        long ans1 = 0, ans2 = 0; ;


        for(int i = 0; i < a.Length; ++i)
        {
            if (i % 2 == 0) ans1 += a[i];
            else ans2 += a[i];
        }

        wr.wri(ans1 - ans2);
            
        }
    }


    class Scan
    {
    public string str => Console.ReadLine();

    public string[] strarr => str.Split(' ');

    public long[] longarr => strarr.Select(long.Parse).ToArray();

   
    }
    
    class write
{
    public void wri<Type>(Type x)
    {
        Console.WriteLine(x);
    }
}