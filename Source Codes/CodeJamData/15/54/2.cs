using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R3D_LogSet
    {
        const bool logEnabled = false;
        static string baseFileName = "D-large";
        string inputFile = baseFileName + ".in";
        string outputFile = baseFileName + ".out";
        string logFile = baseFileName + ".log";
        StreamReader reader;
        StreamWriter writer;
        StreamWriter logWriter;
        private void Log(string message)
        {
            if (!logEnabled) return;
            logWriter.WriteLine(message);
        }

        private string Result { get; set; }

        private int P { get; set; }
        private long TotalF { get; set; }
        private List<long> E;
        private List<long> F;

        private void ReadInput()
        {
            char[] sep = { ' ' };
            P = Int32.Parse(reader.ReadLine());

            var line1 = reader.ReadLine().Split(sep);
            var line2 = reader.ReadLine().Split(sep);

            E = new List<long>();
            F = new List<long>();
            for (int i = 0; i < P; i++)
            {
                var e = Int64.Parse(line1[i]);
                var f = Int64.Parse(line2[i]);
                E.Add(e);
                F.Add(f);
                TotalF += f;
            }
        }

        private bool Check(long elem)
        {
            var neg = (elem < 0);
            var e = Math.Abs(elem);
            var tempE = new List<long>(E);
            var tempF = new List<long>(F);
            var tempF2 = new long[tempF.Count];

            for (int i = 0; i < tempE.Count; i++)
            {
                if (tempF[i] > 0)
                {
                    var e1 = tempE[i];
                    var e2 = e1 + e;
                    var index = tempE.BinarySearch(e2);
                    if (index < 0) return false;
                    if (tempF[index] < tempF[i]) return false;
                    if (e == 0)
                    {
                        if ((tempF[index] % 2) != 0) return false;
                        tempF2[i] = tempF[i] / 2;
                        tempF[i] = 0;
                    }
                    else
                    {
                        tempF[index] -= tempF[i];
                        if (neg) tempF2[index] += tempF[i];
                        else tempF2[i] += tempF[i];
                        tempF[i] = 0;
                    }
                }
            }
            F = new List<long>(tempF2);
            return true;
        }

        private void Solve()
        {
            List<long> found = new List<long>();

            while (TotalF > 1)
            {
                for (int i = 0; i < P; i++)
                {
                    if (F[i] > 0)
                    {
                        // try
                        var e = E[i];
                        if (Check(e))
                        {
                            found.Add(e);
                            TotalF /= 2;
                            break;
                        }
                    }
                }
            }

            var sb = new StringBuilder("");
            for (int i = 0; i < found.Count; i++)
            {
                sb.AppendFormat("{0} ", found[i]);
            }
            Result = sb.ToString();
            Result = Result.Substring(0, Result.Length - 1);
        }

        public void Run()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            if (logEnabled)
                logWriter = new StreamWriter(logFile);
            try
            {
                string s = reader.ReadLine();
                int T = Int32.Parse(s);
                for (int t = 1; t <= T; t++)
                {
                    Log("Start Case #" + t);
                    ReadInput();
                    Solve();
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Result));
                    Log("End Case #" + t);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
                if (logEnabled)
                    logWriter.Close();
            }
        }
        static void Main(string[] args)
        {
            new R3D_LogSet().Run();
        }
    }
}
