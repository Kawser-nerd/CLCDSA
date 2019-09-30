using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace gcj
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader sr = new System.IO.StreamReader(@"D:\other\gcj\A-large.in");
            System.IO.StreamWriter sw = new System.IO.StreamWriter(@"D:\other\gcj\ans.txt");

            string tmp = sr.ReadLine();
            int cas = Int32.Parse(tmp);

            for (int i = 0; i < cas; i++)
            {
                int a, b;
                double ans;
                tmp = sr.ReadLine();
                string[] arr = tmp.Split(' ');
                a = Int32.Parse(arr[0]);
                b = Int32.Parse(arr[1]);
                ans = b + 2;
                tmp = sr.ReadLine();
                arr = tmp.Split(' ');
                double[] d = new double[a];
                for (int j = 0; j < a; j++)
                {
                    d[j] = double.Parse(arr[j]);
                }

                double f = 1;
                for (int j = 0; j < a; j++)
                {
                    f *= d[j];
                    double t = (1 + 2 * (a - j - 1) + (b - a)) + (1 - f) * (b + 1);
                    ans = Math.Min(ans,t);
                }

                sw.WriteLine("Case #{0}: {1}", i + 1, Math.Round(ans, 6).ToString("#0.000000"));
            }

            sr.Close();
            sw.Close();
        }
    }
}
