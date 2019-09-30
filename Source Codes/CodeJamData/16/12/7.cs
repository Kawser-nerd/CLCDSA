using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R1AB_RankAndFile
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

        string Result;
        int N;
        int[] Table;

        private void ReadInput()
        {
            N = int.Parse(reader.ReadLine());
            Table = new int[2502];
            for (int i = N * 2 - 1; i > 0; i--)
            {
                var line = reader.ReadLine().Split(" ".ToCharArray());
                for (int j=0;j< N;j++)
                {
                    Table[int.Parse(line[j])]++;
                }
            }
        }

        private string Solve()
        {
            Result = "";
            for (int i=0;i<Table.Length;i++)
            {
                if (Table[i] % 2 == 1)
                {
                    Result = Result + " " + i;
                }
            }
            return Result.Trim();
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
            new R1AB_RankAndFile().Run();
        }
    }
}
