using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R1AA_Mushroom
    {
        const bool logEnabled = false;
        static string baseFileName = "A-large";
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

        private int N { get; set; }
        private List<int> Mushrooms { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            N = Int32.Parse(reader.ReadLine());
            var line = reader.ReadLine().Split(sep);
            Mushrooms = new List<int>();
            foreach (var token in line)
            {
                Mushrooms.Add(Int32.Parse(token));
            }
        }

        private int Solve1()
        {
            int result = 0;
            for (int i = 1; i < N; i++)
            {
                result += Math.Max(0, Mushrooms[i - 1] - Mushrooms[i]);
            }
            return result;
        }

        private int Solve2()
        {
            int result = 0;
            int maxDownSlope = 0;
            for (int i = 1; i < N; i++)
            {
                maxDownSlope = Math.Max(maxDownSlope, Mushrooms[i - 1] - Mushrooms[i]);
            }
            for (int i = 0; i < N - 1; i++)
            {
                result += Math.Min(maxDownSlope, Mushrooms[i]);
            }
            return result;
        }

        private void Solve()
        {
            Result = String.Format("{0} {1}", Solve1(), Solve2());
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
            new R1AA_Mushroom().Run();
        }
    }
}
