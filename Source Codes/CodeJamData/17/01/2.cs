using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R0A_Pancake_Flipper
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
        int K;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            S = line[0];
            K = int.Parse(line[1]);
        }

        private string Solve()
        {
            var result = 0;
            var happy = S.ToCharArray().Select(p => (p == '+')).ToArray();
            for (int i = 0; i <= happy.Length - K; i++)
            {
                if (!happy[i])
                {
                    result++;
                    for (int j = 0; j < K; j++)
                    {
                        happy[i + j] = !happy[i + j];
                    }
                }
            }
            for (int i = happy.Length - K + 1; i < happy.Length; i++)
            {
                if (!happy[i])
                {
                    return "IMPOSSIBLE";
                }
            }
            return result.ToString();
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
            new R0A_Pancake_Flipper().Run();
        }
    }
}
