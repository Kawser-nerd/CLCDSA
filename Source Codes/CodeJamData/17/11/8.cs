using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R1AA_Alphabet_Cake
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

        private class Position
        {
            public int I { get; set; }
            public int J { get; set; }
            public Position (int i, int j)
            {
                I = i;
                J = j;
            }
        }

        int R, C;
        char[][] Grid;
        Queue<Position> Q = new Queue<Position>();

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            R = int.Parse(line[0]);
            C = int.Parse(line[1]);
            Grid = new char[R][];
            Q.Clear();
            for (int i=0;i< R;i++)
            {
                Grid[i] = new char[C];
                var row = reader.ReadLine();
                for (int j=0;j< C;j++)
                {
                    Grid[i][j] = row[j];
                    if (Grid[i][j] != '?')
                    {
                        Q.Enqueue(new Position(i, j));
                    }
                }
            }

        }

        private bool CheckAndFill(int top, int bottom, int left, int right, char c)
        {
            if ((top < 0) || (left < 0) || (bottom >= R) || (right >= C)) return false;
            for (int i=top; i<= bottom; i++)
            {
                for (int j = left; j <= right; j++)
                    if (Grid[i][j] != '?') return false;
            }
            for (int i = top; i <= bottom; i++)
            {
                for (int j = left; j <= right; j++)
                    Grid[i][j] = c;
            }
            return true;
        }

        private string Solve()
        {
            var result = new StringBuilder();
            while (Q.Count > 0)
            {
                var pos = Q.Dequeue();
                var c = Grid[pos.I][pos.J];
                var top = pos.I;
                var bottom = pos.I;
                var left = pos.J;
                var right = pos.J;
                while (CheckAndFill(top - 1, top - 1, left, right, c)) top--;
                while (CheckAndFill(top, bottom, left - 1, left - 1, c)) left--;
                while (CheckAndFill(top, bottom, right + 1, right + 1, c)) right++;
                while (CheckAndFill(bottom + 1, bottom + 1, left, right, c)) bottom++;
            }
            for (int i=0;i< R;i++)
            {
                result.AppendLine();
                for (int j=0;j< C;j++)
                {
                    result.Append(Grid[i][j]);
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
                    writer.WriteLine(String.Format("Case #{0}:{1}", t, Solve()));
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
            new R1AA_Alphabet_Cake().Run();
        }
    }
}
