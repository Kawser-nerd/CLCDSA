using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R1BB_Noisy
    {
        const bool logEnabled = false;
        static string baseFileName = "B-large";
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

        private int R { get; set; }
        private int C { get; set; }
        private int N { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);
            R = Int32.Parse(line[0]);
            C = Int32.Parse(line[1]);
            N = Int32.Parse(line[2]);
        }

        private void Solve()
        {
            int cells = R * C;
            int extra = N - (cells + 1) / 2;
            int noisy = 0;
            if (extra <= 0)
            {
                Result = "0";
                return;
            }

            int walls = (R * C * 2) - (R + C);

            if (Math.Min(R, C) == 1)
            {
                if (cells % 2 == 0)
                {
                    noisy += 1;
                    extra -= 1;
                }
                noisy += (extra * 2);
                Result = noisy.ToString();
                return;
            }

            int inner = (R - 2) * (C - 2);
            int innerMesh = (inner + 1) / 2;
            int empty = cells - N;

            if (empty <= innerMesh)
            {
                Result = (walls - (4 * empty)).ToString();
                return;
            }

            int wallGaps = ((R - 2) / 2 + (C - 2) / 2) * 2;
            if (empty <= innerMesh + wallGaps)
            {
                int openGaps = empty - innerMesh;
                Result = (walls - (4 * innerMesh) - (3 * openGaps)).ToString();
                return;
            }

            int corners = Math.Min(2, extra);
            if (cells % 2 == 0)
            {
                noisy += (corners * 2);
                extra -= corners;
            }
            noisy += (extra * 3);

            Result = noisy.ToString();
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
            new R1BB_Noisy().Run();
        }
    }
}
