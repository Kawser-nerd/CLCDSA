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

        var p1 = sc.longarr;
        long n = p1[0];
        var p2 = sc.longarr;
        long k = p2[0];

        n %= 500;
        if (n - k <= 0) Console.WriteLine("Yes");
        else Console.WriteLine("No");

            
        }
    }


    class Scan
    {
    public string str => Console.ReadLine();

    public string[] strarr => str.Split(' ');

    public long[] longarr => strarr.Select(long.Parse).ToArray();

   
    }