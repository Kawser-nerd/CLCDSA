using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Globalization;

namespace CodeJamQ1
{
    class Problem3
    {
        StreamReader fin = new StreamReader("p2.in");
        StreamWriter fout = new StreamWriter("p2.out");

        double[] acc = new double[250];
        double[] nTime = new double[1001];
        double[] nPos = new double[1001];
        void RunTestCase(int tn)
        {
            double d = (double)ReadDec();
            int n = ReadInt();
            int a = ReadInt();

            for (int k = 0; k < n; k++)
            {
                nTime[k] = (double)ReadDec();
                nPos[k] = (double)ReadDec();
            }
            //nTime[n] = nTime[n - 1] + 0.0000001m;
            //nPos[n++] = 10000000m;

            fout.WriteLine("Case #{0}:", tn + 1);
            for (int k = 0; k < a; k++)
            {
                acc[k] = (double)ReadDec();
                double ac = acc[k];
                double v = 0;
                double t = 0;
                double curPos = 0;
                bool found = false;

                double brakeT = -1.0;
                double brakeV = -1.0;
                double brakeS = -1.0;

                for (int j = 0; j < n; j++)
                {
                    double nt = nTime[j];
                    double deltaT = nt - t;

                    double posIfNoBrakes = curPos + v * deltaT + 0.5 * ac * deltaT * deltaT;
                    if (nPos[j] >= d && posIfNoBrakes >= d)
                    {
                        double timeToHitDCar = 0;
                        if (j > 0 && nPos[j - 1] < d)
                        {
                            double speed = (nPos[j] - nPos[j - 1]) / deltaT;
                            timeToHitDCar = (d - nPos[j - 1]) / speed;
                        }

                        double deltaS = d - curPos;
                        double mySpeed = (double)Math.Sqrt((double)(v * v + 2.0 * ac * deltaS));
                        double timeToHitMe = (2 * deltaS) / (v + mySpeed);

                        fout.WriteLine("{0}", Math.Max(timeToHitDCar, timeToHitMe) + t);
                        found = true;
                        break;
                    }
                    if (posIfNoBrakes > nPos[j])
                    {
                        curPos = nPos[j];
                        t = nt;
                        v = (curPos - (j > 0 ? nPos[j - 1] : 0)) / deltaT;

                        brakeT = nt;
                        brakeV = v;
                        brakeS = curPos;
                    }
                    else
                    {
                        curPos = posIfNoBrakes;
                        t = nt;
                        v = v + ac * deltaT;
                    }
                }

                if (!found)
                {
                    if (brakeT < 0)
                    {
                        double deltaS2 = d - curPos;
                        double mySpeed2 = (double)Math.Sqrt((double)(v * v + 2.0 * ac * deltaS2));
                        double timeToHitMe2 = (2 * deltaS2) / (v + mySpeed2) + t;

                        fout.WriteLine("{0}", timeToHitMe2);
                    }
                    else
                    {
                        double deltaS2 = d - brakeS;
                        double mySpeed2 = (double)Math.Sqrt((double)(brakeV * brakeV + 2.0 * ac * deltaS2));
                        double timeToHitMe2 = (2 * deltaS2) / (brakeV + mySpeed2) + brakeT;

                        fout.WriteLine("{0}", timeToHitMe2);
                    }
                }
            }

        }

        void Run()
        {
            int t = ReadInt();

            for (int tn = 0; tn < t; tn++)
            {
                RunTestCase(tn);
            }

            fin.Close();
            fout.Close();
        }

        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            Problem3 p = new Problem3();
            p.Run();
        }

        #region Input
        string _ln = null;
        int _lnPos = 0;

        string _Next()
        {
            if (_ln == null || _lnPos >= _ln.Length) {
                _ln = fin.ReadLine();
                _lnPos = 0;
            }

            int idx = _ln.IndexOf(' ', _lnPos);
            if (idx < 0)
            {
                string r = _ln.Substring(_lnPos);
                _ln = null;
                return r;
            }

            string ret = _ln.Substring(_lnPos, idx - _lnPos);
            _lnPos = idx + 1;
            return ret;
        }

        string ReadLine()
        {
            _ln = null;
            return fin.ReadLine();
        }

        int ReadInt()
        {
            return int.Parse(_Next());
        }

        decimal ReadDec()
        {
            return decimal.Parse(_Next(), CultureInfo.InvariantCulture);
        }

        string ReadWord()
        {
            return _Next();
        }
        #endregion
    }
}
