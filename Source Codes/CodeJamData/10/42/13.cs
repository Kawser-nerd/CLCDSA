using System;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Programm
    {
        static void Main(string[] args)
        {
            StreamReader fileIn = new StreamReader("input.txt");
            string[] mass = fileIn.ReadToEnd().Split(new string[] { Environment.NewLine, "\n" }, StringSplitOptions.RemoveEmptyEntries);
            fileIn.Close();
            int c = int.Parse(mass[0]) + 1;
            int fr = 1;
            char[] splitter = new char[] { ' ' };
            StreamWriter wr = new StreamWriter("output.txt");
            for (int z = 1; z != c; z++)
            {
                int n = int.Parse(mass[fr++]);
                int step;
                int rez = 0;
                string[] tmps = mass[fr++].Split(splitter, StringSplitOptions.RemoveEmptyEntries);
                int[] A = new int[tmps.Length];
                step = tmps.Length;
                for (int i = 0; i != step; i++)
                {
                    A[i] = n - int.Parse(tmps[i]);
                }
                for (int i = 0; i != n; i++)
                {
                    fr++;
                }
                while (step != 1)
                {
                    int st = 0;
                    while (st != tmps.Length)
                    {
                        int tmp = st + step;
                        bool ok = false;
                        for (int i = st; i != tmp; i++)
                        {
                            if (A[i] > 0)
                            {
                                ok = true;
                                rez++;
                                break;
                            }
                        }
                        if (ok)
                        {
                            for (int i = st; i != tmp; i++)
                            {
                                A[i]--;
                            }
                        }
                        st = tmp;
                    }
                    step >>= 1;
                }
                wr.WriteLine("Case #{0}: {1}", z, rez);
            }
            wr.Close();
        }
    }
}
