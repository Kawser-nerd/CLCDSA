using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R0D_Omino
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

        private int X { get; set; }
        private int R { get; set; }
        private int C { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);

            X = Int32.Parse(line[0]);
            R = Int32.Parse(line[1]);
            C = Int32.Parse(line[2]);
        }

        private bool Fillable()
        {
            var area = R * C;
            var width = Math.Min(R, C);
            var pieces = area / X;
            var remainder = area % X;

            if (remainder != 0) return false;
            if (X > 6) return false;
            if (X < 3) return true;
            if (width < (X + 1) / 2) return false;
            if (X == 3) return true;
            if (X == 4) return (width > 2);
            if (X == 5) return (pieces > 3);
            // (X == 6)
            return (width > 3);
        }

        private void Solve()
        {
            Result = Fillable() ? "GABRIEL" : "RICHARD";
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
            new R0D_Omino().Run();
        }
    }
}
