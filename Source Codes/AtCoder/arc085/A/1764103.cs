using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;

class Program
{
    static void Main()
    {
        Scanner cin = new Scanner();
        //Random rnd = new Random();
        //Stopwatch sw = new Stopwatch();

        // A B C
        int N = cin.Nextint;
        int M = cin.Nextint;



        long t = 1;
        for(int i=0;i<M;i++){
            t = t*2;
        }
        //Console.WriteLine("t:{0}",t);
        long r = (1900*M +100*(N-M))*t;

        // N
        // a1 a2 ... aN
        /*
        int N;
        int[] A;

        N = cin.Nextint;
        A = cin.Scanint;
        */

        // N M
        // a1 b1
        // ...
        // aM bM
        /*
        int N;
        int M;
        int[] A = new int[M];
        int[] B = new int[M];

        N = cin.Nextint;
        M = cin.Nextint;

        for(int i=0; i<M; i++)
        {
            A[i] = cin.Nextint;
            B[i] = cin.Nextint;
        }
         */




        /** ????? */

        Console.WriteLine(r);
        //Console.WriteLine(result ? "Yes" : "No");
        Console.Out.Flush();
    }
}

class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] Scan { get { return Console.ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length)
            {
                return s[i++];
            }
            string st = Console.ReadLine();
            while (st == "")
            {
                st = Console.ReadLine();
            }

            s 
            = st.
                Split
                (cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}