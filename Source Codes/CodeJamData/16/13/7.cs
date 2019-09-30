using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R1AC_BFFs
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
        int[] BFF;

        int[] Chain;
        int[] Group;
        int Max;

        private void ReadInput()
        {
            N = int.Parse(reader.ReadLine());
            BFF = new int[N + 2];

            var line = reader.ReadLine().Split(" ".ToCharArray());
            for (int i = 1; i <= N; i++)
            {
                BFF[i] = int.Parse(line[i - 1]);
            }
        }

        private void FindChains(int i)
        {
            var b = BFF[i];
            if (Group[b] == 0)
            {
                FindChains(b);
            }
            Group[i] = Group[b];
            Chain[i] = Chain[b] + 1;
        }

        private int LongestChain(int i)
        {
            var x = 0;
            for (int j = 1; j <= N; j++)
            {
                if (Group[j] == i && Chain[j] > x) x = Chain[j];
            }
            return x;
        }

        private string Solve()
        {
            Max = 0;
            var pair = new int[N + 2];
            var loop = new int[N + 2];
            Chain = new int[N + 2];
            Group = new int[N + 2];
            // find pairs
            for (int i = 1; i <= N; i++)
            {
                if (pair[i] == 0 && BFF[BFF[i]] == i)
                {
                    pair[i] = BFF[i];
                    pair[BFF[i]] = i;
                    Group[i] = i;
                    Group[BFF[i]] = BFF[i];
                    Chain[i] = 1;
                    Chain[BFF[i]] = 1;
                    loop[i] = -1;
                    loop[BFF[i]] = -1;
                }
            }

            // find loops
            for (int k = 1; k <= N; k++)
            {
                if (loop[k] == 0)
                {
                    var i = k;
                    loop[i] = 1;
                    while (loop[BFF[i]] == 0)
                    {
                        loop[BFF[i]] = loop[i] + 1;
                        i = BFF[i];
                    }
                    if (loop[BFF[i]] > 0)
                    {
                        var x = loop[i] + 1 - loop[BFF[i]];
                        if (x > Max) Max = x;
                        for (int j = 1; j <= N; j++)
                        {
                            if (loop[j] >= loop[BFF[i]]) Group[j] = i;
                        }
                    }
                    for (int j=1;j<= N;j++)
                    {
                        if (loop[j] > 0) loop[j] = -1;
                    }
                }
            }

            // find chains
            for (int i = 1; i <= N; i++)
            {
                if (Group[i] == 0)
                {
                    FindChains(i);
                }
            }
            var chainSum = 0;
            for (int i = 1; i <= N; i++)
            {
                if (pair[i] > i)
                {
                    var b = pair[i];
                    chainSum += LongestChain(i) + LongestChain(b);
                }
            }
            if (chainSum > Max) Max = chainSum;

            return Max.ToString();
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
            new R1AC_BFFs().Run();
        }
    }
}
