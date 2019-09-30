using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace LoadTesting
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader fin = new StreamReader("in.txt");
            StreamWriter fout = new StreamWriter("out.txt");

            int t = Int32.Parse(fin.ReadLine());

            for (int ncase = 0; ncase < t; ncase++)
            {
                string[] toks = fin.ReadLine().Split(' ');
                long l = Int32.Parse(toks[0]);
                long p = Int32.Parse(toks[1]);
                long c = Int32.Parse(toks[2]);
                long[] tests = new long[100];
                long nc = l;
                long ic = 0;
                while (nc < p)
                {
                    nc *= c;
                    tests[ic++] = nc;
                }
                ic--;
                int notests;
                if (ic <= 0)
                    notests = 0;
                else
                    notests = (int)(Math.Floor(Math.Log(ic, 2)) + 1);
                fout.WriteLine("Case #{0}: {1}",ncase+1,notests);
            }
            fin.Close();
            fout.Close();
        }
    }
}
