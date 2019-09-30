using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R1BA_Counter
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
        private long N { get; set; }
        private static long[] Exp;

        private void ReadInput()
        {
            N = Int64.Parse(reader.ReadLine());
        }

        private void Solve()
        {
            long moves = 0;
            if (N % 10 == 0)
            {
                N--;
                moves++;
            }
            int len = N.ToString().Length;

            for (int i = 0; i < len - 1; i++)
            {
                moves += 9;
                for (int j = 1; j <= i; j++)
                {
                    moves += Exp[(Math.Min(i - j, j))] * 9;
                }
                if (i > 0) moves++;
            }

            // 1000....000
            char[] digits = N.ToString().ToCharArray();
            for (int i = 0; i < len; i++)
            {
                moves += Exp[(Math.Min(len - i - 1, i))] * (digits[i] - '0');
            }
            if (len > 1)
            {
                if (digits[0] > '1')
                {
                    moves++;
                }
                else
                {
                    for (int i = 1; i < len / 2; i++)
                    {
                        if (digits[i] > '0')
                        {
                            moves++;
                            break;
                        }
                    }
                }
            }

            Result = moves.ToString();
        }

        private void Init()
        {
            Exp = new long[9];
            Exp[0] = 1;
            for (int i = 1; i < Exp.Length; i++)
            {
                Exp[i] = Exp[i - 1] * 10;
            }
        }

        public void Run()
        {
            Init();
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
            new R1BA_Counter().Run();
        }
    }
}
