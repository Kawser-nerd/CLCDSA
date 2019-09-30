using System;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void fill(bool[,] A, int q, int w, int e, int r)
        {
            q--;
            w--;
            for (int i = q; i != e; i++)
            {
                for (int j = w; j != r; j++)
                {
                    A[i, j] = true;
                }
            }
        }
        static void Main(string[] args)
        {
            StreamReader fileIn = new StreamReader("input.txt");
            string[] mass = fileIn.ReadToEnd().Split(new string[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);
            fileIn.Close();
            int c = int.Parse(mass[0])+1;
            int fr = 1;
            char[] splitter = new char[]{' '};
            StreamWriter wr = new StreamWriter("output.txt");
            for (int z = 1; z != c; z++)
            {
                int n = int.Parse(mass[fr++]);
                bool[,] A = new bool[100, 100];
                for (int i = 0; i != n; i++)
                {
                    string[] tmps = mass[fr++].Split(splitter, StringSplitOptions.RemoveEmptyEntries);
                    fill(A, int.Parse(tmps[0]), int.Parse(tmps[1]), int.Parse(tmps[2]), int.Parse(tmps[3]));
                }
                int kol;
                int rez = 0;
                do
                {
                    kol = 0;
                    rez++;
                    bool[,] pred = A;
                    A = new bool[100, 100];
                    A[0, 0] = false;
                    for (int i = 1; i != 100; i++)
                    {
                        if ((pred[0, i]) && (pred[0, i - 1]))
                        {
                            A[0, i] = true;
                            kol++;
                        }
                        if ((pred[i, 0]) && (pred[i - 1, 0]))
                        {
                            A[i, 0] = true;
                            kol++;
                        }
                    }
                    for (int i = 1; i != 100; i++)
                    {
                        for (int j = 1; j != 100; j++)
                        {
                            if (pred[i, j])
                            {
                                if ((pred[i - 1, j]) || (pred[i, j - 1]))
                                {
                                    A[i, j] = true;
                                    kol++;
                                }
                            }
                            else
                            {
                                if ((pred[i - 1, j]) && (pred[i, j - 1]))
                                {
                                    A[i, j] = true;
                                    kol++;
                                }
                            }
                        }
                    }
                } while (kol != 0);
                wr.WriteLine("Case #{0}: {1}", z, rez);
            }
            wr.Close();
        }
    }
}
