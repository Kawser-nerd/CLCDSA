using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R0B_Pancakes
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

        private string Result { get; set; }

        private int D;
        private int[] Diners;
        private int maxPancakes;

        private void ReadInput()
        {
            char[] sep = { ' ' };

            D = Int32.Parse(reader.ReadLine());

            var line = reader.ReadLine().Split(sep);

            maxPancakes = 0; 
            Diners = new int[1002];
            foreach (string num in line)
            {
                var p = Int32.Parse(num);
                Diners[p]++;
                if (p > maxPancakes) maxPancakes = p;
            }
        }

        private void Solve()
        {
            var best = maxPancakes;
            for (int i = maxPancakes - 1; i >= 1; i--)
            {
                var moves = 0;
                for (int j = maxPancakes; j > i; j--)
                {
                    moves += Diners[j] * ((j - 1) / i);
                }
                if (i + moves < best) 
                    best = i + moves;
            }
            Result = best.ToString();
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
            new R0B_Pancakes().Run();
        }
    }
}
