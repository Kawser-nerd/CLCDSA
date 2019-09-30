using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R0D_Fractiles
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

        int K;
        int C;
        int S;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToArray());

            K = int.Parse(line[0]);
            C = int.Parse(line[1]);
            S = int.Parse(line[2]);
        }

        private string Solve()
        {
            if (S * C < K)
            {
                return "IMPOSSIBLE";
            }
            long maxBlock = 1;
            for (int i = 1; i < C; i++)
            {
                maxBlock *= K;
            }
            var result = new List<string>();
            for (int i = 0; i < K; i += C)
            {
                long index = 0;
                long step = maxBlock;
                for (int j = 0; j < C; j++)
                {
                    index += (step * ((i + j) % K));
                    step /= K;
                }
                index++;
                result.Add(index.ToString());
            }
            return string.Join(" ", result);
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
            new R0D_Fractiles().Run();
        }
    }
}
