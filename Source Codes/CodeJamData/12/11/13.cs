using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "A-large";
            //string filename = "A-small-attempt0";
            //string filename = "test";

            string[] inLine = File.ReadAllLines(filename + ".in");
            int T = Convert.ToInt32(inLine[0]);
            string[] outLine = new String[T];

            for (int t = 1; t <= T; t++)
            {
                double result = 0;
                string[] tmp = inLine[2*t-1].Split(' ');
                string[] tmp2 = inLine[2*t].Split(' ');

                int A = Convert.ToInt32(tmp[0]);
                int B = Convert.ToInt32(tmp[1]);
                double [] p = new double[A];
                for (int i = 0; i < A; i++)
                {
                    p[i] = Convert.ToDouble(tmp2[i]);
                }

                // press enter and input again

                result = 1 + B + 1;

                // backspace 0 - A times

                for (int i = 0; i <= A; i++)
                {
                    double correctrate = 1;
                    for (int j = 0; j < A - i; j++)
                    {
                        correctrate *= p[j];
                    }
                    double estimate_keycount = correctrate * (i * 2 + B - A + 1) + (1 - correctrate) * (i * 2 + B - A + 1 + B + 1);
                    result = Math.Min(result, estimate_keycount);

                }





                outLine[t - 1] = "Case #" + t.ToString() + ": " + result.ToString("F6");
            }

            File.WriteAllLines(filename + ".out", outLine);

        }
    }
}
