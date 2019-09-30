using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.IO;

namespace CJ
{
    class Program
    {
        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter(@"C:\output.txt");
            string[] lines = System.IO.File.ReadAllLines(@"C:\input.txt");
            int lineid = 0;
            string line = lines[lineid++];
            int T = int.Parse(line);



            for (int t = 1; t <= T; t++)
            {
                string [] num = lines[lineid++].Split();
                int N = int.Parse(num[0]);
                int M = int.Parse(num[1]);
                int [,] p = new int[N,M];
                int [,] q = new int[N,M];
                int [] c = new int[M];
                int [] r = new int[N];
                for(int i=0; i<N; i++)
                {
                    num = lines[lineid++].Split();
                    for (int j = 0; j < M; j++)
                    {
                        p[i,j]=int.Parse(num[j]);
                        c[j] = Math.Max(c[j], p[i, j]);
                        r[i] = Math.Max(r[i], p[i, j]);
                    }
                }
                Boolean ok = true;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        q[i, j] = Math.Min(c[j], r[i]);
                        if (q[i, j] != p[i, j]) ok = false;
                    }
                }


                Console.WriteLine("Case #" + t + ": " + (ok?"YES":"NO"));
                tw.WriteLine("Case #" + t + ": " + (ok ? "YES" : "NO"));

            }

            Console.WriteLine("FINE");
            tw.Close();
        }
        
    }

}
