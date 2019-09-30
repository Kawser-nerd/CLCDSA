using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R0A_CountingSheep
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

        string Result;
        int N;

        private void ReadInput()
        {
            var line = reader.ReadLine();

            N = Int32.Parse(line);
        }

        private string Solve()
        {
            if (N <= 0)
            {
                return "INSOMNIA";
            }
            else
            {
                var digits = new List<char>("0123456789");
                var current = N;
                while (true)
                {
                    digits.RemoveAll(current.ToString().Contains);
                    if (digits.Count == 0)
                    {
                        return current.ToString();
                    }
                    current += N;
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
            new R0A_CountingSheep().Run();
        }
    }
}
