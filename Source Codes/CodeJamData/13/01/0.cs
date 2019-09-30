using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Solver
        {
            private bool Check(string[] board, char ch, int row, int col, int dr, int dc)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (board[row + i * dr][col + i * dc] != 'T' &&
                        board[row + i * dr][col + i * dc] != ch)
                    {
                        return false;
                    }
                }
                return true;
            }

            public string Solve(string[] board)
            {
                int res = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (Check(board, 'X', i, 0, 0, 1) || Check(board, 'X', 0, i, 1, 0))
                    {
                        res = 1;
                        break;
                    }
                    if (Check(board, 'O', i, 0, 0, 1) || Check(board, 'O', 0, i, 1, 0))
                    {
                        res = 2;
                        break;
                    }
                }
                if (Check(board, 'X', 0, 0, 1, 1) || Check(board, 'X', 3, 0, -1, 1))
                {
                    res = 1;
                }
                if (Check(board, 'O', 0, 0, 1, 1) || Check(board, 'O', 3, 0, -1, 1))
                {
                    res = 2;
                }

                if (res == 0)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (board[i][j] == '.')
                            {
                                res = 3;
                            }
                        }
                    }
                }

                return new string[] { "Draw", "X won", "O won", "Game has not completed" }[res];
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            //string filename = "A-small-attempt0";
            string filename = "A-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int N = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < N; i++)
                    {
                        string[] board = new string[4];
                        board[0] = reader.ReadLine();
                        board[1] = reader.ReadLine();
                        board[2] = reader.ReadLine();
                        board[3] = reader.ReadLine();
                        reader.ReadLine();

                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(board));
                    }
                }
            }
        }
    }
}
