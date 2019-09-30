using System;
using System.Diagnostics;
using System.IO;

namespace fashion
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader("D-small-attempt1.in"));
            //Console.SetOut(new StreamWriter("small.out"));
            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int[] tokens = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                int n = tokens[0];
                int m = tokens[1];
                int[,] board = new int[n, n];
                bool[,] board0 = new bool[n, n];
                bool[,] board1 = new bool[n, n];
                for (int j = 0; j < m; j++)
                {
                    string[] tks = Console.ReadLine().Split(' ');
                    int r = int.Parse(tks[1]) - 1;
                    int c = int.Parse(tks[2]) - 1;
                    int type = 0;
                    switch (tks[0])
                    {
                        case "x":
                            type = 1;
                            break;
                        case "+":
                            type = 2;
                            break;
                        case "o":
                            type = 3;
                            break;
                    }
                    board[r, c] = type;
                    if (type == 1 || type == 3)
                        board0[r, c] = true;
                    if (type == 2 || type == 3)
                        board1[r, c] = true;
                }
                // Fill board0 and board1 according to the usual rules
                // board0 (x) must be filled optimally, not sharing rows or columns
                OptimizeNoRowsColumns(board0);
                // board1 (+) must be filled optimally, not sharing diagonals
                OptimizeNoDiagonals(board1);

                // Calculate score
                int score = 0;
                int stones = 0;
                int[,] finalBoard = new int[n, n];
                int s0 = 0;
                int s1 = 0;
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < n; c++)
                    {
                        if (board0[r, c])
                        {
                            score++;
                            finalBoard[r, c] = 1;
                            s0++;
                        }
                        if (board1[r, c])
                        {
                            score++;
                            finalBoard[r, c] = 2;
                            s1++;
                        }
                        if (board0[r, c] && board1[r, c])
                        {
                            finalBoard[r, c] = 3;
                        }
                        if (finalBoard[r, c] != board[r, c])
                            stones++;
                    }
                }                                
                Console.WriteLine("Case #{0}: {1} {2}", (i + 1), score, stones);
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < n; c++)
                    {
                        if (finalBoard[r, c] != board[r, c])
                        {
                            string type = "";
                            if (finalBoard[r, c] == 1)
                                type = "x";
                            else if (finalBoard[r, c] == 2)
                                type = "+";
                            else if (finalBoard[r, c] == 3)
                                type = "o";
                            Console.WriteLine("{0} {1} {2}", type, r+1, c+1);
                        }
                    }
                }
            }
            //Console.Out.Flush();
        }

        private static void OptimizeNoDiagonals(bool[,] board)
        {
            int n = board.GetLength(0);
            bool[] diag0 = new bool[n*2-1];
            bool[] diag1 = new bool[n*2-1];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i, j])
                    {
                        diag0[i-j + (n-1)] = true;
                        diag1[i+j] = true;
                    }
                }
            }

            foreach (int i in new int[]{0, n-1})
            {
                for (int j = 0; j < n; j++)
                {                    
                        if (!diag0[i - j + (n - 1)] && !diag1[i + j])
                        {
                            board[i, j] = true;
                            diag0[i - j + (n - 1)] = true;
                            diag1[i + j] = true;
                        }
                    
                }
            }        
        }

        private static void OptimizeNoRowsColumns(bool[,] board0)
        {
            int n = board0.GetLength(0);
            bool[] row = new bool[n];
            bool[] col = new bool[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board0[i, j])
                    {
                        row[i] = true;
                        col[j] = true;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!row[i] && !col[j])
                    {
                        board0[i, j] = true;
                        row[i] = true;
                        col[j] = true;
                    }
                }
            }        
        }
    }
}
