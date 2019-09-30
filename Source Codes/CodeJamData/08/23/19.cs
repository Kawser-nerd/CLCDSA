using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Mousetrap
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int T = int.Parse(sr.ReadLine()); // number of cases
            int K;
            int n;
            int[] ki;



            for (int i = 1; i <= T; i++)
            {
                K = int.Parse(sr.ReadLine()); // deck size
                ki = new int[K];
                int ci = 0;
                for (int x = 1; x <= K; x++)
                {
                    int steps = 0;
                    while (steps < x)
                    {
                        ci++;
                        if (ci > K) ci = 1; 
                        if (ki[ci-1] ==0) steps++;
                    }
                    ki[ci - 1] = x;
                }

                string[] inp = sr.ReadLine().Split(" ".ToCharArray());
                string outp = "";
                n = int.Parse(inp[0]);
                for (int x = 1; x <= n; x++)
                {
                    outp = outp + " " + ki[int.Parse(inp[x]) - 1].ToString();
                }


                Console.WriteLine("Case #{0}:{1}", i, outp);
                sw.WriteLine("Case #{0}:{1}", i, outp);

            }

            sr.Close();
            sw.Flush();
            sw.Close();

        }
    }
}
