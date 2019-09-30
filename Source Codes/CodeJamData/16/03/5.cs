using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R0C_CoinJam
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

        int N;
        int J;
        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToArray());

            N = int.Parse(line[0]);
            J = int.Parse(line[1]);
        }

        private string Solve()
        {
            StringBuilder builder = new StringBuilder("");
            // assuming N is either 16 or 32
            // assuming target J will be met before easy candidates with block size 2 run out
            var blocks = new string[] { "00", "11" };
            var divisors = "3 4 5 6 7 8 9 10 11";
            var inner = N / 2 - 2;
            for (int i = 0; i < J; i++)
            {
                var b = new StringBuilder("11");
                var x = i;
                for (int j = 0; j < inner; j++)
                {
                    b.Append(blocks[x % 2]);
                    x /= 2;
                }
                b.Append("11");
                builder.AppendLine();
                builder.Append(b.ToString() + " " + divisors);
            }

            return builder.ToString();
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
            new R0C_CoinJam().Run();
        }
    }
}
