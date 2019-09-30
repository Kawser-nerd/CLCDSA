using System;
using System.IO;

namespace Tic_Tac_Toe_Tomek
{
    class Program
    {
        private static bool IsRowWin(char[][] board, int row, char player)
        {
            for (int col = 0; col < board.Length; col++)
            {
                if (board[row][col] != player) return false;
            }

            return true;
        }

        private static bool IsColumnWin(char[][] board, int col, char player)
        {
            for (int row = 0; row < board.Length; row++)
            {
                if (board[row][col] != player) return false;
            }

            return true;
        }

        private static bool IsFirstDiagonalWin(char[][] board, char player)
        {
            for (int i = 0; i < board.Length; i++)
            {
                if (board[i][i] != player) return false;
            }

            return true;
        }

        private static bool IsSecondDiagonalWin(char[][] board, char player)
        {
            for (int i = 0; i < board.Length; i++)
            {
                if (board[i][board.Length - i - 1] != player) return false;
            }

            return true;
        }

        private static bool IsWin(char[][] board, char player)
        {
            for (int i = 0; i < board.Length; i++)
            {
                if (IsRowWin(board, i, player)) return true;
                if (IsColumnWin(board, i, player)) return true;
            }

            if (IsFirstDiagonalWin(board, player)) return true;
            if (IsSecondDiagonalWin(board, player)) return true;

            return false;
        }

        private static bool IsTomekWin(char[][] board, char player)
        {
            for (int row = 0; row < board.Length; row++)
            {
                for (int col = 0; col < board.Length; col++)
                {
                    if (board[row][col] == 'T')
                    {
                        board[row][col] = player;
                        bool isWin = IsWin(board, player);
                        board[row][col] = 'T';

                        return isWin;

                    }
                }
            }

            return false;
        }

        private static bool IsGameCompleted(char[][] board)
        {
            for (int row = 0; row < board.Length; row++)
            {
                for (int col = 0; col < board.Length; col++)
                {
                    if (board[row][col] == '.') return false;
                }
            }

            return true;
        }

        static void Main(string[] args)
        {
            try
            {
                string path = @"C:\Work\Trainings\Code Jam\2013 Qualification\Tic-Tac-Toe-Tomek\";
                string filenameIn = "A-large.in";
                string filenameOut = "A-large.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                const int size = 4;
                for (int t = 0; t < testCount; t++)
                {
                    char[][] board = new char[size][];
                    for (int i = 0; i < size; i++)
                    {
                        board[i] = sr.ReadLine().ToCharArray();
                    }

                    sr.ReadLine();

                    string message;
                    if (IsWin(board, 'X') || IsTomekWin(board, 'X'))
                    {
                        message = "X won";
                    }
                    else if (IsWin(board, 'O') || IsTomekWin(board, 'O'))
                    {
                        message = "O won";
                    }
                    else if (IsGameCompleted(board))
                    {
                        message = "Draw";
                    }
                    else
                    {
                        message = "Game has not completed";
                    }

                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }

        }
    }
}
