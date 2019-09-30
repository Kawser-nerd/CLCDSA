using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R2C_Gardener
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

        int R, C, N;
        int[] Pairs;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            R = int.Parse(line[0]);
            C = int.Parse(line[1]);
            N = 2 * (R + C);
            Pairs = new int[N];
            line = reader.ReadLine().Split(" ".ToCharArray());

            for (int i = 0; i < N; i += 2)
            {
                var x = int.Parse(line[i]) - 1;
                var y = int.Parse(line[i + 1]) - 1;
                Pairs[x] = y;
                Pairs[y] = x;
            }
        }

        bool[] used;
        char[][] grid;

        private bool CloseEnough(int i)
        {
            int target = Pairs[i];
            int j;
            for (j=(i+1)% N;j!= target; j = (j+1)% N)
            {
                if (used[j] == false) break;
            }
            return (j == target);
        }

        private bool Traverse(int source, int target)
        {
            int[] istep = { -1, 0, 1, 0 };
            int[] jstep = { 0, 1, 0, -1 };
            int d;
            int i, j;
            int ti, tj;

            // from top
            if (source < C)
            {
                d = 2;
                i = -1;
                j = source;
            }
            // from right
            else if (source < C + R)
            {
                d = 3;
                i = source - C;
                j = C;
            }
            // from bottom
            else if (source < C + R + C)
            {
                d = 0;
                i = R;
                j = C - 1 - (source - C - R);
            }
            // from left
            else
            {
                d = 1;
                i = R - 1 - (source - C - R - C);
                j = -1;
            }


            // to top
            if (target < C)
            {
                ti = 0;
                tj = target;
            }
            // to right
            else if (target < C + R)
            {
                ti = target - C;
                tj = C - 1;
            }
            // to bottom
            else if (target < C + R + C)
            {
                ti = R - 1;
                tj = C - 1 - (target - C - R);
            }
            // to left
            else
            {
                ti = R - 1 - (target - C - R - C);
                tj = 0;
            }
            
            while (i != ti || j != tj)
            {
                i += istep[d];
                j += jstep[d];
                if (i < 0 || i >= R || j < 0 || j >= C)
                {
                    return false;
                }
                if (grid[i][j] == '/')
                {
                    d = d ^ 1;
                }
                else if (grid[i][j] == '\\')
                {
                    d = 3 - d;
                }
                else
                {
                    grid[i][j] = (d % 2 == 0) ? '\\' : '/';
                    d = (d + 3) % 4;
                }
            }

            return true;
        }

        private string Solve()
        {
            used = new bool[N];
            grid = new char[R][];
            for (int i = 0; i < R; i++)
            {
                grid[i] = "".PadRight(C, ' ').ToCharArray();
            }

            var hasProgress = true;
            while (hasProgress)
            {
                hasProgress = false;
                for (int i = 0; i < N; i++)
                {
                    if (!used[i] && CloseEnough(i))
                    {
                        hasProgress = true;
                        if (!Traverse(i, Pairs[i])) return "IMPOSSIBLE\r\n";
                        used[i] = true;
                        used[Pairs[i]] = true;
                    }
                }
            }

            return used.All(u => u) ? FormatGrid() : "IMPOSSIBLE\r\n";
        }

        private string FormatGrid()
        {
            var builder = new StringBuilder();
            for (int i = 0; i < R; i++)
                builder.AppendLine((new string(grid[i])).Replace(' ', '/'));
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
                    //writer.Write(String.Format("Case #{0}: {1}", t, Solve()));
                    writer.WriteLine(String.Format("Case #{0}:", t));
                    writer.Write(String.Format("{1}", t, Solve()));
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
            new R2C_Gardener().Run();
        }
    }
}
