using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace RopeIntranet
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
                int n = Int32.Parse(fin.ReadLine());
                int[] a = new int[n];
                int[] b = new int[n];
                int pts = 0;
                for (int i = 0; i < n; i++)
                {
                    string[] toks = fin.ReadLine().Split(' ');
                    a[i] = Int32.Parse(toks[0]);
                    b[i] = Int32.Parse(toks[1]);
                    for (int j = 0; j < i; j++)
                    {
                        if (((a[i] - a[j]) * (b[i] - b[j])) < 0)
                        {
                            pts++;
                        }
                    }
                }
                fout.WriteLine("Case #{0}: {1}", ncase + 1, pts);
            }
            fin.Close();
            fout.Close();
        }
    }
}
