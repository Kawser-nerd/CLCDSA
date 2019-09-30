using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static private double Solve(double C, double F, double X)
        {
            double t1 = X / 2;
            double t = 0;
            double v = 2;
            for (int i = 0; true; i++)
            {
                t += C / v;
                v += F;
                double t2 = t + X / v;
                if (t1 <= t2) { return t1; }
                t1 = t2;
            }
        }
        static void Main(string[] args)
        {
            string filename = "../B-large";
            StreamReader sr = new StreamReader(filename + ".in");
            StreamWriter sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                double[] values = Array.ConvertAll(sr.ReadLine().Split(' '), double.Parse);
                double res = Solve(values[0], values[1], values[2]);
                sw.WriteLine("Case #{0}: {1}", i, res);
                Console.WriteLine("Case #{0}: {1}", i, res);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
