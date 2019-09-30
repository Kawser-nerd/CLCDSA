using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R0C_Dijkstra
    {
        const bool logEnabled = false;
        static string baseFileName = "C-large";
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
        private string Pattern { get; set; }
        private int L { get; set; }
        private long X { get; set; }

        private static int[][] ValueMap = { new[] { 0, 1, 2, 3 }, new[] { 1, 0, 3, 2 }, new[] { 2, 3, 0, 1 }, new[] { 3, 2, 1, 0 } };
        private static int[][] SignMap = { new[] { 0, 0, 0, 0 }, new[] { 0, 1, 0, 1 }, new[] { 0, 1, 1, 0 }, new[] { 0, 0, 1, 1 } };
        private static string[] SymbolMap = { "1", "i", "j", "k" };

        private static string[] Targets = { "i", "j", "k" };

        private class Quaternion
        {
            private int Sign { get; set; }
            private int Value { get; set; }

            public Quaternion(char x)
            {
                Sign = 0;
                Value = x - 'h';
            }

            public Quaternion(int sign, int value)
            {
                Sign = sign;
                Value = value;
            }

            public void MultiplyBy(char y)
            {
                var yValue = y - 'h';
                Sign ^= SignMap[Value][yValue];
                Value = ValueMap[Value][yValue];
            }

            public override string ToString()
            {
                return (Sign == 0 ? "" : "-") + SymbolMap[Value];
            }
        }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);

            L = Int32.Parse(line[0]);
            X = Int64.Parse(line[1]);

            Pattern = reader.ReadLine();
        }

        private void Solve()
        {
            int found = 0;
            Quaternion current = new Quaternion(0, 0);
            if (X > 12)
            {
                X = (X % 4) + 12;
            }

            for (int i = 0; i < X; i++)
            {
                var patternChars = Pattern.ToCharArray();
                for (int j = 0; j < L; j++)
                {
                    current.MultiplyBy(patternChars[j]);
                    if ((found < Targets.Length - 1) && (current.ToString() == Targets[found]))
                    {
                        found++;
                        current = new Quaternion(0, 0);
                    }
                }
            }

            Result = ((found == Targets.Length - 1) && (current.ToString() == Targets[found])) ? "YES" : "NO";
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
            new R0C_Dijkstra().Run();
        }
    }
}
