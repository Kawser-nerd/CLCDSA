using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R0B_RevengeOfThePancakes
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

        string Pancakes;

        private void ReadInput()
        {
            var line = reader.ReadLine();

            Pancakes = line + '+';
        }

        private string Solve()
        {
            var flips = 0;
            for (int i=1;i<Pancakes.Length;i++)
            {
                if (Pancakes[i - 1] != Pancakes[i])
                    flips++;
            }
            return flips.ToString();
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
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Solve()));
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
            new R0B_RevengeOfThePancakes().Run();
        }
    }
}
