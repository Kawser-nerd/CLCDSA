using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R0D_Fashion_Show
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

        int N;
        int M;
        char[][] grid;
        int score;
        bool[][] plusInvalid;
        bool[][] xInvalid;
        int plusValidCount;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = int.Parse(line[0]);
            M = int.Parse(line[1]);
            grid = new char[N][];
            for (int i = 0; i < N; i++)
            {
                grid[i] = new char[N];
                for (int j = 0; j < N; j++)
                {
                    grid[i][j] = '.';
                }
            }
            score = 0;
            for (int i = 0; i < M; i++)
            {
                line = reader.ReadLine().Split(" ".ToCharArray());
                var r = int.Parse(line[1]);
                var c = int.Parse(line[2]);
                grid[r - 1][c - 1] = line[0][0];
                if (line[0][0] == 'o') score += 2;
                else if (line[0][0] != '.') score++;
            }
        }

        private void MarkXInvalid(int i, int j)
        {
            for (int k = 0; k < N; k++)
            {
                xInvalid[i][k] = true;
                xInvalid[k][j] = true;
            }
        }

        private int MarkPlusInvalid(int i, int j, bool commitChange)
        {
            var countA = 0;
            var countB = 0;
            for (int k = 1; k < N; k++)
            {
                if ((i + k < N) && (j + k < N))
                {
                    if (!plusInvalid[i + k][j + k]) countA++;
                    plusInvalid[i + k][j + k] |= commitChange;
                }
                if ((i + k < N) && (j - k >= 0))
                {
                    if (!plusInvalid[i + k][j - k]) countB++;
                    plusInvalid[i + k][j - k] |= commitChange;
                }
                if ((i - k >= 0) && (j + k < N))
                {
                    if (!plusInvalid[i - k][j + k]) countB++;
                    plusInvalid[i - k][j + k] |= commitChange;
                }
                if ((i - k >= 0) && (j - k >= 0))
                {
                    if (!plusInvalid[i - k][j - k]) countA++;
                    plusInvalid[i - k][j - k] |= commitChange;
                }
            }
            plusInvalid[i][j] |= commitChange;
            if (commitChange) plusValidCount -= (countA + countB + 1);
            return Math.Min(countA, countB);
        }

        private string Solve()
        {
            var result = new StringBuilder();
            var updated = new bool[N][];
            var updatedCount = 0;
            plusInvalid = new bool[N][];
            xInvalid = new bool[N][];
            plusValidCount = N * N;
            for (int i = 0; i < N; i++)
            {
                plusInvalid[i] = new bool[N];
                xInvalid[i] = new bool[N];
                updated[i] = new bool[N];
            }
            for (int i=0;i< N;i++)
            {
                for (int j=0;j< N;j++)
                {
                    if (grid[i][j] != '.')
                    {
                        if (grid[i][j] != '+')
                        {
                            MarkXInvalid(i, j);
                        }
                        if (grid[i][j] != 'x')
                        {
                            MarkPlusInvalid(i, j, true);
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (!xInvalid[i][j])
                    {
                        updatedCount++;
                        updated[i][j] = true;
                        grid[i][j] = (grid[i][j] == '+') ? 'o' : 'x';
                        score++;
                        MarkXInvalid(i, j);
                    }
                }
            }
            while (plusValidCount > 0)
            {
                var minFree = new int[N][];
                for (int i=0;i< N;i++)
                {
                    minFree[i] = new int[N];
                    for (int j=0;j< N;j++)
                    {
                        minFree[i][j] = int.MaxValue;
                    }
                }
                var besti = -1;
                var bestj = -1;
                var minCover = int.MaxValue;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (!plusInvalid[i][j])
                        {
                            var cover = MarkPlusInvalid(i, j, false);
                            if (cover < minCover)
                            {
                                minCover = cover;
                                besti = i;
                                bestj = j;
                            }
                        }
                    }
                }
                if (!updated[besti][bestj])
                {
                    updated[besti][bestj] = true;
                    updatedCount++;
                }
                grid[besti][bestj] = (grid[besti][bestj] == 'x') ? 'o' : '+';
                score++;
                MarkPlusInvalid(besti, bestj, true);
            }

            result.AppendFormat("{0} {1}", score, updatedCount);
            for (int i=0;i< N;i++)
            {
                for (int j=0;j< N;j++)
                {
                    if (updated[i][j])
                    {
                        result.AppendLine();
                        result.AppendFormat("{0} {1} {2}", grid[i][j], i + 1, j + 1);
                    }
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
            new R0D_Fashion_Show().Run();
        }
    }
}
