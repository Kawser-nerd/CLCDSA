using System;
using System.Collections.Generic;
using System.IO;

class MainClass
{
    public class Solver
    {
        public int n, x;
        public int[] s;

        public string Solve()
        {
            int[] total = new int[x+1];

            for(int i = 0; i<n; i++)
            {
                total[s[i]]++;
            }


            int d = 0;

            for(int i = 1; i<=x; i++)
            {
                int j = x - i;

                while(total[i] > 0)
                {
                    total[i]--;
                    d++;

                    while (j>=0 && total[j]==0) j--;

                    if (j >= 0)
                        total[j]--;

                }

            }


            return d.ToString();
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

        for(int c = 1; c<=T; c++)
        {
            Solver s = new Solver();
            int[] x = ReadIntVec();
            s.n = x[0];
            s.x = x[1];
            s.s = ReadIntVec();


            string ret = s.Solve();

            w.WriteLine("Case #{0}: {1}", c, ret);
            Console.WriteLine("Case #{0}: {1}", c, ret);
        }

        w.Close();
        r.Close();
    }

}
