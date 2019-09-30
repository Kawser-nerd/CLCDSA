using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round3ProblemA
{
    class Program
    {
        struct Point
        {
            public int x;
            public double y;
            public Point(int xx, double yy)
            {
                x = xx;
                y = yy;
            }
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round3ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    int W = int.Parse(s[0]);
                    int L = int.Parse(s[1]);
                    int U = int.Parse(s[2]);
                    int G = int.Parse(s[3]);
                    Point[] PL = new Point[L];
                    Point[] PU = new Point[U];
                    for (int i = 0; i < L; ++i)
                    {
                        s = sr.ReadLine().Split();
                        PL[i].x = int.Parse(s[0]);
                        PL[i].y = int.Parse(s[1]);
                    }
                    for (int i = 0; i < U; ++i)
                    {
                        s = sr.ReadLine().Split();
                        PU[i].x = int.Parse(s[0]);
                        PU[i].y = int.Parse(s[1]);
                    }
                    int il = 0;
                    int iu = 0;
                    double x0 = 0;
                    double y0u = PU[0].y;
                    double y0l = PL[0].y;
                    double S = 0;
                    List<Point> P = new List<Point>();
                    P.Add(new Point(0, y0u - y0l));
                    while (x0 < W)
                    {
                        int x;
                        double yNu;
                        double yNl;
                        if (PU[iu + 1].x < PL[il + 1].x)
                        {
                            iu++;
                            x = PU[iu].x;
                            yNu = PU[iu].y;
                            yNl = y0l + (PL[il + 1].y - y0l) * (x - x0) / (PL[il + 1].x - x0);
                        }
                        else if (PU[iu + 1].x > PL[il + 1].x)
                        {
                            il++;
                            x = PL[il].x;
                            yNl = PL[il].y;
                            yNu = y0u + (PU[iu + 1].y - y0u) * (x - x0) / (PU[iu + 1].x - x0);
                        }
                        else
                        {
                            il++;
                            iu++;
                            x = PL[il].x;
                            yNl = PL[il].y;
                            yNu = PU[iu].y;
                        }
                        S += (yNu + y0u - yNl - y0l) * (x - x0);
                        P.Add(new Point(x, yNu - yNl));
                        x0 = x;
                        y0u = yNu;
                        y0l = yNl;
                    }
                    S /= 2;
                    double SG = S / G;
                    double SP = 0;
                    double[] res = new double[G - 1];
                    int guest = 0;
                    for (int pos = 0; pos < P.Count - 1; ++pos)
                    {
                        double ST = (P[pos].y + P[pos + 1].y) * (P[pos + 1].x - P[pos].x) / 2;
                        double xp = P[pos].x;
                        double hp = P[pos].y;
                        double Sn = SG - SP;
                        while (Sn <= ST)
                        {
                            double a = (P[pos + 1].y - hp) / (P[pos + 1].x - xp);
                            double x;
                            if (Math.Abs(a) < 1e-6)
                                x = xp + (Sn / hp);
                            else
                                x = xp + (Math.Sqrt(hp * hp + 2 * Sn * a) - hp) / a;
                            double y = hp + a * (x - xp);
                            if (guest < res.Length)
                            {
                                res[guest] = x;
                                guest++;
                            }
                            else
                            {
                                System.Diagnostics.Debug.Assert(pos + 2 == P.Count);
                                System.Diagnostics.Debug.Assert(Math.Abs(Sn - ST) <= 1e-6);
                            }
                            SP = 0;
                            xp = x;
                            hp = y;
                            ST -= Sn;
                            Sn = SG;
                        }
                        SP += ST;
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ":");
                    for (int i = 0; i < res.Length; i++)
                        sw.WriteLine(res[i].ToString("F8", CultureInfo.InvariantCulture));
                }
            }
        }
    }
}
