using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R1AA_LastWord
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
        string S;

        private void ReadInput()
        {
            S = reader.ReadLine();
        }

        private string Solve()
        {
            var maxChar = S.Max();
            var flush = false;
            Result = "";
            foreach (var c in S)
            {
                if (c == maxChar)
                {
                    Result = c + Result;
                    flush = true;
                }
                else if (flush)
                {
                    Result = Result + c;
                }
                else if (Result.Length > 0 && Result[0] > c)
                {
                    Result = Result + c;
                }
                else    
                {
                    Result = c + Result;
                }
            }
            return Result;
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
            new R1AA_LastWord().Run();
        }
    }
}
