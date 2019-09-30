using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ1CC
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("B-small-attempt1.in");
            StreamWriter sw = new StreamWriter("out.txt");

            int T;
            T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string ss = sr.ReadLine();
                double D = double.Parse(ss.Split(' ')[0]);
                int N = int.Parse(ss.Split(' ')[1]);
                string[] str;
                List<double> NN = new List<double>();
                List<double> TT = new List<double>();
                for (int j = 0; j < N; j++)
                {
                    ss = sr.ReadLine();
                    NN.Add(double.Parse(ss.Split(' ')[1]));
                    TT.Add(double.Parse(ss.Split(' ')[0]));
                }
                str = sr.ReadLine().Split(' ');
                List<double> a = new List<double>();
                foreach (string s in str)
                    a.Add(double.Parse(s));
                sw.WriteLine("Case #{0}:\n", i + 1);
                for (int j = 0; j < a.Count; j++)
                {
                    if (N == 1)
                    {
                        sw.WriteLine(Math.Sqrt(2 * D / a[j]));
                        continue;
                    }
                    double pret = 0, pres = 0;
                    for (int nextp = 1; nextp < N; nextp++)
                    {
                        if (NN[nextp] - D > 1e-8)
                        {
                            TT[nextp] = TT[nextp - 1] + (TT[nextp] - TT[nextp - 1]) * (D - NN[nextp - 1]) / (NN[nextp] - NN[nextp - 1]);
                            NN[nextp] = D;
                        }
                        double tt;
                        if (nextp == 1) tt = (Math.Sqrt(pres * pres + 2 * a[j] * NN[nextp]) - pres) / (a[j]);
                        else tt = (Math.Sqrt(pres * pres + 2 * a[j] *  (NN[nextp]-NN[nextp-1])) - pres) / (a[j]);
                        if (tt + pret > TT[nextp])
                        {
                            pret = tt + pret;
                            pres = pres + a[j] * tt;
                        }
                        else
                        {
                            pret = TT[nextp];
                            pres = (NN[nextp] - NN[nextp - 1]) / (TT[nextp] - TT[nextp - 1]);
                        }
                    }
                    sw.WriteLine(pret);
                }
            }

            sr.Close();
            sw.Close();
        }
    }
}
