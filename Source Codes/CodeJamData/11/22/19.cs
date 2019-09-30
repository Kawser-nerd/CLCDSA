using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam
{
    class Program
    {
        static int[][] binary;
        static char[][] combine = new char[26][];
        static bool[][] oppose = new bool[26][];

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("B-Small.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int Case = int.Parse(sr.ReadLine());
            int[] Points = new int[105];
            Console.WriteLine(Case);
            for (int i = 0; i < Case; i++)
            {
                string[] words = sr.ReadLine().Split(' ');
                int C = int.Parse(words[0]);
                int D = int.Parse(words[1]);
                int t = 0; //num of points
                for (int j = 0; j < C; j++)
                {
                    words = sr.ReadLine().Split(' ');
                    int l = int.Parse(words[0]);
                    int num = int.Parse(words[1]);
                    for (int k = 0; k < num; k++)
                    {
                        t = t + 1;
                        Points[t] = l;
                    }
                }
                double T = 0.0;
                while (T <= 500) // N * D
                {
                    double x = -T;
                    bool tt = true;
                    for (int m = t - 1; m >= 1; m--)
                    {
                        double lb = x + D - (Points[m + 1] - Points[m]);
                        if (lb > T)
                        {
                            tt = false;
                            break;
                        }
                        if (lb < -T) lb = -T;
                        x = lb;
                    }
                    if (tt == true)
                    {
                        break;
                    }
                    T = T + 0.5;
                }
                sw.WriteLine("Case #" + (i + 1) + ": " + T);
                Console.WriteLine("Case #" + (i + 1) + ": " + T);

            }
            sw.Close();
        }
    }
}
