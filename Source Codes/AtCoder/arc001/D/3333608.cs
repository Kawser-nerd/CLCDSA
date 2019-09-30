using System;
using System.Collections.Generic;
using System.Text;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?
            char[][] board = new char[8][];

            int i = 0;
            // ??????????????
            while (i<8)
            {
                board[i++] = Console.ReadLine().ToCharArray();
            }
          
            // ??????????????No Answer
            if (!CheckQueen(board))
            {
                Console.WriteLine("No Answer");
                return;
            }

            // ???????????
            int[] col = new int[8];
            List<int> colList = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7 };

            // ???????????
            int[] row = new int[5];
            List<int> rowList = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7 };

            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if (board[y][x] == 'Q')
                    {
                        colList.Remove(x);
                        rowList.Remove(y);
                    }
                }
            }
            col = colList.ToArray();
            row = rowList.ToArray();

            for (int a = 0; a < 8; a++)
            {
                board[row[0]][a] = 'Q';
                for (int b = 0; b < 8; b++)
                {
                    board[row[1]][b] = 'Q';
                    for (int c = 0; c < 8; c++)
                    {
                        board[row[2]][c] = 'Q';
                        for (int d = 0; d < 8; d++)
                        {
                            board[row[3]][d] = 'Q';
                            for (int e = 0; e < 8; e++)
                            {
                                board[row[4]][e] = 'Q';
                                if (CheckQueen(board))
                                {
                                    StringBuilder sb = new StringBuilder();
                                    for (int j = 0; j < board.Length; j++)
                                    {
                                        sb.Append(new string(board[j]));
                                        sb.Append(System.Environment.NewLine);
                                    }

                                    string output = sb.ToString();

                                    Console.WriteLine(output);
                                  return;
                                }
                                board[row[4]][e] = '.';
                            }
                            board[row[3]][d] = '.';
                        }
                        board[row[2]][c] = '.';
                    }
                    board[row[1]][b] = '.';
                }
                board[row[0]][a] = '.';
            }
            Console.WriteLine("No Answer");
          return;
        }

        private static bool CheckQueen(char[][] board)
        {
            char[][] masu = board;

            int x = 0, y = 0, z = 0;
            int count = 0;

            // ??????
            for (x = 0; x < 8; x++)
            {
                count = 0;
                for (y = 0; y < 8; y++)
                {
                    if (masu[y][x] == 'Q')
                    {
                        count++;
                    }
                }
                if (count > 1)
                {
                    return false;
                }
            }

            // ??????
            for (y = 0; y < 8; y++)
            {
                count = 0;
                for (x = 0; x < 8; x++)
                {
                    if (masu[y][x] == 'Q')
                    {
                        count++;
                    }
                }
                if (count > 1)
                {
                    return false;
                }
            }

            // ??(?)?????
            for (z = -7; z <= 7; z++)
            {
                count = 0;
                for (y = 0; y < 8; y++)
                {
                    for (x = 0; x < 8; x++)
                    {
                        if (y - x == z)
                        {
                            if (masu[y][x] == 'Q')
                            {
                                count++;
                            }
                        }
                    }
                }
                if (count > 1)
                {
                    return false;
                }
            }

            // ??(?)?????
            for (z = 0; z <= 14; z++)
            {
                count = 0;
                for (y = 0; y < 8; y++)
                {
                    for (x = 0; x < 8; x++)
                    {
                        if ((x + y) == z)
                        {
                            if (masu[y][x] == 'Q')
                            {
                                count++;
                            }
                        }
                    }
                }
                if (count > 1)
                {
                    return false;
                }
            }
            return true;
        }
    }
}