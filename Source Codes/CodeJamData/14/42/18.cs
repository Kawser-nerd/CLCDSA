using System;
using System.Collections.Generic;
using System.IO;

class MainClass
{
    public class Solver
    {
        public int n;
        public int[] a;
        int cost = 0;

        public void swap(int i)
        {
            cost++;
            int x = a[i];
            a[i] = a[i+1];
            a[i+1] = x;
        }

        public string Solve()
        {
            int max = 0;

            for(int i = 1; i<n; i++)
            {
                int cnt1 = 0;
                int j,k;
                max = 0;

                for(j = i+1; j<n; j++)
                {
                    if (a[j] > a[i]) cnt1++;
                }

                for(j = 0; j<i; j++)
                {
                    if (a[j] > a[max])
                        max = j;
                }

                if (a[i] >= a[max])
                {
                    for(j = i-1; j>max; j--)
                        swap(j);
                } else
                {
                    j = i;
                    while (j>1 && j > max && a[j-1] < a[j])
                    {
                        swap(j-1);
                        j--;
                    }
                    // j

                    for(k = max; k>0; k--)
                    {
                        if (a[k-1] <= a[j]) break;
                    }

                    if (cnt1 > j-k)
                    {
                        for(; j>k; j--)
                            swap(j-1);
                    }



                }


            }


            return cost.ToString();
        }

    }

    static TextReader r;
    static TextWriter w;
    static int T;


    public static int ReadInt()
    {
        return int.Parse(r.ReadLine());
    }

    public static int[] ReadIntVec()
    {
        string[] x = r.ReadLine().Split(' ');
        int[] y = new int[x.Length];
        for(int i = 0; i<y.Length; i++)
            y[i] = int.Parse(x[i]);

        return y;
    }

    public static void Main(string[] args)
    {
        r = new StreamReader(args[0]);
        w = new StreamWriter(Path.ChangeExtension(args[0], "out"));

        T = ReadInt();
        Solver s;

        for(int c = 1; c<=T; c++)
        {
            s = new Solver();
     
            s.n = ReadInt();
            s.a = ReadIntVec();

            string ret = s.Solve();

            w.WriteLine("Case #{0}: {1}", c, ret);
            Console.WriteLine("Case #{0}: {1}", c, ret);
        }

        /*
        s = new Solver();
        s.n = 10000;
        s.a = new int[s.n];

        Random rr = new Random();
        for(int i = 0; i<s.n; i++)
            s.a[i] = rr.Next(1000000);

        Console.WriteLine(s.Solve());
        */

        w.Close();
        r.Close();
    }

}
