using System;
using System.Globalization;
using System.Text;
using System.Collections.Generic;
using System.IO;

//The first line of input gives the number of cases, N. N test cases follow. 
//Each test case consists of one line containing the integers n, A, B, C, D, x0, y0 and M separated by exactly one space. 
//n will be the number of trees in the input set. Using the numbers n, A, B, C, D, x0, y0 and M the 
//following pseudocode will print the coordinates of the trees in the input set. mod indicates the remainder operation. 

//The parameters will be chosen such that the input set of trees will not have duplicates. 

//X = x0, Y = y0
//print X, Y
//for i = 1 to n-1
//  X = (A * X + B) mod M
//  Y = (C * Y + D) mod M
//  print X, Y

class Program
{
    static void Main(string[] args)
    {

        string infile = "A-large.in";
        string outfile = "agysejt_large.out";
        //string infile = "A-small-attempt0.in";
        //string outfile = "A-small-attempt0.out";
        //string infile = "in.txt";
        //string outfile = "out.txt";

        TextReader tr = new StreamReader(infile);
        TextWriter tw = new StreamWriter(outfile);
        string line = tr.ReadLine();
        int t = int.Parse(line);
        for (int iii = 1; iii <= t; iii++)
        {
            long res = 0;

            string[] s = tr.ReadLine().Trim().Split(' ');
            int n = int.Parse(s[0]);
            long A = int.Parse(s[1]);
            long B = int.Parse(s[2]);
            long C = int.Parse(s[3]);
            long D = int.Parse(s[4]);
            long x0 = int.Parse(s[5]);
            long y0 = int.Parse(s[6]);
            long M = int.Parse(s[7]);

            List<long> x = new List<long>();
            List<long> y = new List<long>();
            x.Add(x0);
            y.Add(y0);
            for (int i = 1; i < n; i++)
            {
                x.Add((A * x[i - 1] + B) % M);
                y.Add((C * y[i - 1] + D) % M);
            }

            //for (int i = 0; i < x.Count; i++)
            //    Console.WriteLine(x[i] + ", " + y[i]);

            // elso modszer
            long res1 = 0;
            //for (int i = 0; i < n; i++)
            //    for (int j = i + 1; j < n; j++)
            //        for (int k = j + 1; k < n; k++)
            //            if ((x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0)
            //            {
            //                res1++;
            //            }
            Console.WriteLine("Res1: " + res1);


            long res2 = 0;
            long[,] tipus = new long[3, 3];
            for (int i = 0; i < n; i++)
            {
                tipus[x[i] % 3, y[i] % 3]++;
            }

            // tipusok felsorolasa

            long res2_6 = 0;
            long res2_3 = 0;
            long res2_1 = 0;

            for (int i = 0; i < 3; i++)
                for (int ii = 0; ii < 3; ii++)
                    for (int j = 0; j < 3; j++)
                        for (int jj = 0; jj < 3; jj++)
                            for (int k = 0; k < 3; k++)
                                for (int kk = 0; kk < 3; kk++)
                                {
                                    if ((i + j + k) % 3 == 0 && (ii + jj + kk) % 3 == 0)
                                    {
                                        string p1 = i.ToString() + ii.ToString();
                                        string p2 = j.ToString() + jj.ToString();
                                        string p3 = k.ToString() + kk.ToString();

                                        if (p1 != p2 && p2 != p3 && p1 != p3)
                                        {
                                            long e = tipus[i, ii] * tipus[j, jj] * tipus[k, kk];
                                            res2_6 += e;
                                        }
                                        else if (p1 == p2 && p2 != p3)
                                        {
                                            Console.WriteLine("ERROR");
                                        }
                                        else if (p1 == p2 && p2 == p3 && p1 == p3)
                                        {
                                            long e = tipus[i, ii] * (tipus[j, jj] - 1) * (tipus[k, kk] - 2) / 6;
                                            res2_1 += e;
                                        }
                                    }
                                }

            res2 = (res2_6 / 6) + (res2_3 / 3) + res2_1;
            Console.WriteLine("Res2: " + res2);
            Console.WriteLine(res2_6 + " " + res2_3 + " " + res2_1);

            res = res2;

            Console.WriteLine("Case #{0}: {1}", iii, res);
            tw.WriteLine("Case #{0}: {1}", iii, res);
            //Console.WriteLine((2.25).ToString(CultureInfo.InvariantCulture));
        }
        tw.Close();
        tr.Close();
        Console.ReadLine();
    }

}
