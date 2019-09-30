using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace TriagleA
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D:\\in.txt");
            StreamWriter sw = new StreamWriter("D:\\out.txt");
            int vv = int.Parse(sr.ReadLine());
            for (int w = 0; w < vv; )
            {
                w++;
                string[] t = sr.ReadLine().Split(' ');
                int N = int.Parse(t[0]);
                int M = int.Parse(t[1]);
                int A = int.Parse(t[2]);
                string r = "IMPOSSIBLE";
                for (int x1 = 0; x1 <= N; x1++)
                {
                    for (int y1 = 0; y1 <= M; y1++)
                    {
                        for (int x2 = 0; x2 <= N; x2++)
                        {
                            for (int y2 = 0; y2 <= M; y2++)
                            {
                                if(r=="IMPOSSIBLE")
                                {
                                double a = Math.Sqrt(x1 * x1 + y1 * y1);
                                double b = Math.Sqrt(x2 * x2 + y2 * y2);
                                double c = Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                                double s = (a + b + c) / 2.0;
                                double ff = s * (s - a) * (s - b) * (s - c);
                                if (ff > 0)
                                {
                                    ff = Math.Sqrt(ff) * 2;
                                    if (Math.Abs(ff - A) < 2e-1)
                                        r = "0 0 " + x1.ToString() + " " + y1.ToString() + " " + x2.ToString() + " " + y2.ToString();
                                }
                                }
                            }
                        }
                    }
                }
                string outs = "Case #" + w.ToString() + ": ";
                sw.WriteLine(outs + r);
            }
            sr.Close();
            sw.Close();
        }
    }
}
