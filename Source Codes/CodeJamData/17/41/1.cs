using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R2A_Fresh_Chocolate
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

        int N, P;
        int[] Groups;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = int.Parse(line[0]);
            P = int.Parse(line[1]);
            Groups = new int[P];
            line = reader.ReadLine().Split(" ".ToCharArray());
            foreach (var tok in line)
            {
                Groups[int.Parse(tok) % P]++;
            }
        }

        private string Solve()
        {
            var result = Groups[0];
            N -= Groups[0];
            Groups[0] = 0;
            for (int i=1;i*2< P;i++)
            {
                var min = Math.Min(Groups[i], Groups[P - i]);
                result += min;
                Groups[i] -= min;
                Groups[P - i] -= min;
                N -= (min * 2);
            }
            var h = P / 2;
            if (h*2 == P)
            {
                result += Groups[h] / 2;
                N -= ((Groups[h] / 2) * 2);
                Groups[h] %= 2;
            }
            if ((P == 4) && (Groups[2] == 1) && (N >= 3))
            {
                result++;
                N -= 3;
            }
            result += (N + P - 1) / P;
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
            new R2A_Fresh_Chocolate().Run();
        }
    }
}
