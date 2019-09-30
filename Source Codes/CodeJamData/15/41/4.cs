using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R2A_Pegman
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

        private int R { get; set; }
        private int C { get; set; }
        private List<string> Rows { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);
            R = Int32.Parse(line[0]);
            C = Int32.Parse(line[1]);
            Rows = new List<string>();
            for (int i = 0; i < R; i++)
            {
                Rows.Add(reader.ReadLine());
            }
        }

        private static int[][] steps = { new[] { -1, 0 }, new[] { 0, 1 }, new[] { 1, 0 }, new[] { 0, -1 } };

        private int Check(int i, int j)
        {
            int[] dirs = {};
            switch (Rows[i][j])
            {
                case '.': return 0;
                case '^': 
                    dirs = new[] { 0, 1, 2, 3 };
                    break;
                case '>':
                    dirs = new[] { 1, 0, 2, 3 };
                    break;
                case 'v':
                    dirs = new[] { 2, 1, 0, 3 };
                    break;
                case '<':
                    dirs = new[] { 3, 1, 2, 0 };
                    break;
            }

            for (int d = 0; d < dirs.Length; d++)
            {
                int y = i + steps[dirs[d]][0];
                int x = j + steps[dirs[d]][1];
                while ((x >= 0) && (x < C) && (y >= 0) && (y < R))
                {
                    if (Rows[y][x] != '.')
                    {
                        return Math.Min(1, d);
                    }
                    y += steps[dirs[d]][0];
                    x += steps[dirs[d]][1];
                }
            }

            return -1;
        }

        private void Solve()
        {
            var changes = 0;

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    var c = Check(i, j);
                    if (c == -1)
                    {
                        Result = "IMPOSSIBLE";
                        return;
                    }
                    else changes += c;
                }
            }
            Result = changes.ToString();
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
            new R2A_Pegman().Run();
        }
    }
}
