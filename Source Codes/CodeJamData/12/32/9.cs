using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics;

namespace ConsoleApplication1
{
    class Program
    {
        static string X(string[] s)
        {
            string[] tmp = s[0].Split(' ');

            double d = double.Parse(tmp[0]);

            double[] t = new double[s.Length - 2];
            double[] x = new double[s.Length - 2];

            for (int i = 0; i < s.Length - 2; i++)
            {
                tmp = s[i + 1].Split(' ');

                t[i] = double.Parse(tmp[0]);
                x[i] = double.Parse(tmp[1]);
            }


            tmp = s[s.Length - 1].Split(' ');
            double[] a = new double[tmp.Length];

            for (int i = 0; i < a.Length; i++)
            {
                a[i] = double.Parse(tmp[i]);
            }

            double[] time = new double[a.Length];

            if (t.Length < 2 || x[0]>=d)
            {
                for (int i = 0; i < time.Length; i++)
                {
                    time[i] = Math.Sqrt(2 * d / a[i]);
                }
            }
            else
            {
                for (int i = 0; i < a.Length; i++)
                {
                    time[i] = Math.Sqrt(2 * d / a[i]);

                    double v = (x[1] - x[0])/(t[1]-t[0]);
                    double w = t[0]+(d - x[0]) / v;

                    if (time[i] < w)
                    {
                        time[i] = w;
                    }

                    //double dis = 0.5 * a[i] * t[0] * t[0];

                    //if (x[0] >= dis)
                    //{
                    //    time[i] = Math.Sqrt(2 * d / a[i]);

                    //    double y=(d-x[1])*(t[1]-t[0])/(x[1]-x[0]);

                    //    if (y > time[i])
                    //    {
                    //        time[i] = y;
                    //    }
                    //}
                    //else
                    //{
                    //    time[i] = Math.Sqrt(2 * d / a[i]);
                    //}
                }
            }

            string o = "";
            for (int i = 0; i < time.Length; i++)
            {
                o = o + "\n" + time[i].ToString("F10");
            }

            return o;
        }


        static void Main(string[] args)
        {
            string x = @"C:\Users\a\Desktop\google code jam\test.in";
            StreamReader sr = new StreamReader(x, Encoding.ASCII);

            string s;
            string output = "";

            int n = 0;

            while ((s = sr.ReadLine()) != null)
            {
                if (s == "") continue;

                if (n > 0)
                {
                    string[] t = s.Split(' ');
                    int a = int.Parse(t[1]);

                    List<string> l = new List<string>();
                    l.Add(s);
                    for (int i = 0; i < a + 1; i++)
                    {
                        s = sr.ReadLine();
                        l.Add(s);
                    }
                    string o = X(l.ToArray());
                    output += String.Format("Case #{0}: {1}\n", n, o);
                }

                n++;
            }

            sr.Close();

            StreamWriter writer = new StreamWriter(@"C:\Users\a\Desktop\google code jam\out.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
