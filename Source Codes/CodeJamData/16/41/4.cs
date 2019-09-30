using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R2A_RPS
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

        int N, R, P, S;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = int.Parse(line[0]);
            R = int.Parse(line[1]);
            P = int.Parse(line[2]);
            S = int.Parse(line[3]);
        }

        private string GenerateOutput()
        {
            string[] cur = { "P", "R", "S" };
            string[] next = new string[3];
            for (int i=0;i< N;i++)
            {
                string min, max;
                min = cur[0].CompareTo(cur[1]) <= 0 ? cur[0] : cur[1];
                max = cur[0].CompareTo(cur[1]) > 0 ? cur[0] : cur[1];
                next[0] = min + max;
                min = cur[2].CompareTo(cur[1]) <= 0 ? cur[2] : cur[1];
                max = cur[2].CompareTo(cur[1]) > 0 ? cur[2] : cur[1];
                next[1] = min + max;
                min = cur[0].CompareTo(cur[2]) <= 0 ? cur[0] : cur[2];
                max = cur[0].CompareTo(cur[2]) > 0 ? cur[0] : cur[2];
                next[2] = min + max;
                cur[0] = next[0];
                cur[1] = next[1];
                cur[2] = next[2];
            }
            if (P > 0) return cur[0];
            else if (R > 0) return cur[1];
            else return cur[2];
        }

        private string Solve()
        {
            int nextP = 0, nextR = 0, nextS = 0;
            for (int i=0;i< N;i++)
            {
                nextP = 0;
                nextR = 0;
                nextS = 0;
                while (P + R + S > 0)
                {
                    if (P == R && R == S)
                    {
                        nextP += P / 2;
                        nextR += P / 2;
                        nextS += P / 2;
                        break;
                    }
                    else if (P >= R && P >= S)
                    {
                        if (P > R + S) return "IMPOSSIBLE";
                        var d = P - S;
                        nextP += d;
                        P -= d;
                        R -= d;
                        d = P - R;
                        nextS += d;
                        P -= d;
                        S -= d;
                    }
                    else if (R >= P && R >= S)
                    {
                        if (R > P + S) return "IMPOSSIBLE";
                        var d = R - S;
                        nextP += d;
                        P -= d;
                        R -= d;
                        d = R - P;
                        nextR += d;
                        R -= d;
                        S -= d;
                    }
                    else
                    {
                        if (S > P + R) return "IMPOSSIBLE";
                        var d = S - P;
                        nextR += d;
                        S -= d;
                        R -= d;
                        d = S - R;
                        nextS += d;
                        P -= d;
                        S -= d;
                    }
                    nextP += P / 2;
                    nextR += P / 2;
                    nextS += P / 2;
                    break;
                }
                P = nextP;
                R = nextR;
                S = nextS;
            }
            return GenerateOutput();
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
            new R2A_RPS().Run();
        }
    }
}
