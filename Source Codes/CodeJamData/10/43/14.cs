using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace Round2C
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("F:\\in.in");
            StreamWriter sw = new StreamWriter("F:\\out.out");
            sw.AutoFlush = true;
            int n = int.Parse(sr.ReadLine());
            Console.WriteLine(n);
            for (int i = 0; i < n; i++)
            {
                sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
                Console.WriteLine(i);
            }
            sw.Close();
            sr.Close();
            Console.WriteLine("Finished");
            Console.ReadLine();
        }

        static bool GG(bool[,] A)
        {
            for (int i = 0; i < 102; i++)
            {
                for (int j = 0; j < 102; j++)
                {
                    if (A[i, j])
                        return true;

                }
            }
            return false;
        }

        static string Solution(StreamReader sr)
        {
            int R = int.Parse(sr.ReadLine());
            bool[,] A = new bool[102, 102];
            for (int g = 0; g < R; g++)
            {
                string[] t = sr.ReadLine().Split(' ');
                int x1 = int.Parse(t[0]);
                int y1 = int.Parse(t[1]);
                int x2 = int.Parse(t[2]);
                int y2 = int.Parse(t[3]);
                for (int i = x1; i < x2 + 1; i++)
                {
                    for (int j = y1; j < y2 + 1; j++)
                    {
                        A[i+1, j+1] = true;
                    }
                }
            }
            int r = 0;
            while (GG(A))
            {

                bool[,] B = new bool[102, 102];
                for (int i = 1; i < 102; i++)
                {
                    for (int j = 1; j < 102; j++)
                    {
                        if ((A[i - 1, j] && A[i, j - 1]) || (A[i, j] && (A[i - 1, j] || A[i, j - 1])))
                            B[i, j] = true;
                    }
                }

                A = B;
                r++;
            }
            return r.ToString();
        }
    }
}
