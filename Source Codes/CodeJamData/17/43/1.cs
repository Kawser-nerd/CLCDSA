using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R2C_Beaming_With_Joy
    {
        const bool logEnabled = false;
        static string baseFileName = "C-small-attempt0";
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

        int R, C;
        List<char[]> Grid;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            R = int.Parse(line[0]);
            C = int.Parse(line[1]);
            Grid = new List<char[]>();
            Grid.Add("".PadRight(C + 2, '#').ToCharArray());
            for (int i=0;i< R;i++)
            {
                Grid.Add(('#' + reader.ReadLine() + '#').ToCharArray());
            }
            Grid.Add("".PadRight(C + 2, '#').ToCharArray());
        }

        int[][] MoveDir = new int[][]{
            new [] { -1, 0 },
            new [] { 0, 1 },
            new [] { 1, 0 },
            new [] { 0, -1 }
            };

        private int MoveAndCount(int i, int j, int dir, int accu, bool flip, bool validate)
        {
            var ni = i + MoveDir[dir][0];
            var nj = j + MoveDir[dir][1];
            switch (Grid[i][j])
            {
                case '#':
                    return accu;
                case '/':
                    return MoveAndCount(ni, nj, dir ^ 1, accu, flip, validate);
                case '\\':
                    return MoveAndCount(ni, nj, dir ^ 3, accu, flip, validate);
                case '.':
                case '*':
                    return MoveAndCount(ni, nj, dir, accu, flip, validate);
                default:
                    if (validate && (Grid[i][j] == '-') && (dir % 2 == 0)) return -1;
                    if (validate && (Grid[i][j] == '|') && (dir % 2 == 1)) return -1;
                    if (flip)
                    {
                        Grid[i][j] = (dir % 2 == 0) ? '|' : '-';
                    }
                    return MoveAndCount(ni, nj, dir, accu + 1, flip, validate);
            }
        }

        private int CountHorizontal(int i, int j, bool flip, bool validate)
        {
            return MoveAndCount(i, j - 1, 3, 0, flip, validate) + MoveAndCount(i, j + 1, 1, 0, flip, validate);
        }

        private int CountVertical(int i, int j, bool flip, bool validate)
        {
            return MoveAndCount(i - 1, j, 0, 0, flip, validate) + MoveAndCount(i + 1, j, 2, 0, flip, validate);
        }

        private string Solve()
        {
            const string IMPOSSIBLE = "IMPOSSIBLE";
            for (int i=1;i<= R;i++)
            {
                for (int j=1;j<= C;j++)
                {
                    if ((Grid[i][j] == '-') || Grid[i][j] == '|')
                    {
                        var hor = CountHorizontal(i, j, false, false);
                        var ver = CountVertical(i, j, false, false);
                        if ((hor > 0) && (ver > 0)) return IMPOSSIBLE;
                        else if (hor > 0) Grid[i][j] = '|';
                        else if (ver > 0) Grid[i][j] = '-';
                        else Grid[i][j] = '+';
                    }
                }
            }
            var updated = true;
            var marked = false;
            var mi = 0;
            var mj = 0;
            while (updated)
            {
                updated = false;
                marked = false;
                for (int i = 1; i <= R; i++)
                {
                    for (int j = 1; j <= C; j++)
                    {
                        if (Grid[i][j] == '.')
                        {
                            var hor = CountHorizontal(i, j, false, true);
                            var ver = CountVertical(i, j, false, true);
                            if ((hor != 1) && (ver != 1)) return IMPOSSIBLE;
                            else if (hor != 1)
                            {
                                ver = CountVertical(i, j, true, true);
                                if (ver != 1)
                                {
                                    return IMPOSSIBLE;
                                }
                                updated = true;
                                Grid[i][j] = '*';
                            }
                            else if (ver != 1)
                            {
                                hor = CountHorizontal(i, j, true, true);
                                if (hor != 1)
                                {
                                    return IMPOSSIBLE;
                                }
                                updated = true;
                                Grid[i][j] = '*';
                            }
                            else if (!marked)
                            {
                                marked = true;
                                mi = i;
                                mj = j;
                            }
                        }
                    }
                }
                if (marked && !updated)
                {
                    CountVertical(mi, mj, true, true);
                    updated = true;
                    Grid[mi][mj] = '*';
                }
            }

            var sb = new StringBuilder("POSSIBLE");
            for (int i=1;i<= R;i++)
            {
                sb.AppendLine();
                for (int j=1;j<= C;j++)
                {
                    switch(Grid[i][j])
                    {
                        case '*':
                            sb.Append('.');
                            break;
                        case '+':
                            sb.Append('-');
                            break;
                        default:
                            sb.Append(Grid[i][j]);
                            break;
                    }
                }
            }
            return sb.ToString();
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
            new R2C_Beaming_With_Joy().Run();
        }
    }
}
