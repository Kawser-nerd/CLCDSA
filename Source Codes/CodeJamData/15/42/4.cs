using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R2B_KiddiePool
    {
        const bool logEnabled = false;
        static string baseFileName = "B-small-attempt1";
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

        private int N;
        private double V;
        private double X;
        private List<double> R = new List<double>();
        private List<double> C = new List<double>();

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);
            N = Int32.Parse(line[0]);
            V = Double.Parse(line[1]);
            X = Double.Parse(line[2]);
            R.Clear();
            C.Clear();
            for (int i = 0; i < N; i++)
            {
                line = reader.ReadLine().Split(sep);
                R.Add(Double.Parse(line[0]));
                C.Add(Double.Parse(line[1]));
            }
        }

        private void Solve()
        {
            var lower = false;
            var higher = false;
            var equal = false;
            for (int i = 0; i < N; i++)
            {
                if (C[i] > X) higher = true;
                else if (C[i] < X) lower = true;
                else equal = true;
            }
            if (!equal && !(higher && lower))
            {
                Result = "IMPOSSIBLE";
                return;
            }

            // N <= 2 only
            if (N == 1)
            {
                // must be equal
                double result = V / R[0];
                Result = result.ToString();
                return;
            }

            if (N == 2)
            {
                if (equal == false)
                {
                    var diff0 = Math.Abs(C[0] - X);
                    var diff1 = Math.Abs(C[1] - X);
                    var totalDiff = diff0 + diff1;
                    var vol0 = V * diff1 / totalDiff;
                    var vol1 = V * diff0 / totalDiff;
                    var time0 = vol0 / R[0];
                    var time1 = vol1 / R[1];
                    double result = Math.Max(time0, time1);
                    Result = result.ToString();
                }
                else
                {
                    double rate = 0;
                    for (int i = 0; i < N; i++)
                    {
                        if (C[i] == X)
                            rate += R[i];
                    }
                    double result = V / rate;
                    Result = result.ToString();
                }
            }
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
            new R2B_KiddiePool().Run();
        }
    }
}
