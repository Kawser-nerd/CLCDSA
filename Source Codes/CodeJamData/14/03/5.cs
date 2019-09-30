using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace MinesweeperMaster
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\C-small-attempt1.in");
            //StreamWriter sw = new StreamWriter("D:\\C-small-attempt1.out");

            StreamReader sr = new StreamReader("D:\\C-large.in");
            StreamWriter sw = new StreamWriter("D:\\C-large.out");
            
            int numTestCases = Convert.ToInt32(sr.ReadLine());
            int numImpossible=0;
            for (int i = 0; i < numTestCases; i++)
            {
                string[] str = sr.ReadLine().Split(' ');

                int R = Convert.ToInt32(str[0]);
                int C = Convert.ToInt32(str[1]);
                int M = Convert.ToInt32(str[2]);

                char[,] board = null;

                if(M==R*C-1)
                {
                    board = new char[R, C];

                    for (int j = 0; j < R; j++)
                    {
                        for (int k = 0; k < C; k++)
                        {
                            board[j, k] = '*';
                        }
                    }
                    board[0, 0] = 'c';
                }
                else if (R == 1 && C == 1)
                {
                    board = new char[1, 1];
                    if (M == 0)
                    {
                        board[0, 0] = 'c';
                    }
                    else
                    {
                        board = null;
                    }
                }
                else if (R == 1)
                {
                    board = GetSingleRowBoard(C, M);
                }
                else if (C == 1)
                {
                    board = GetSingleColumnBoard(R, M);
                }
                else if (R == 2)
                {
                    board = GetDoubleRowBoard(C, M);
                }
                else if (C == 2)
                {
                    board = GetDoubleColumnBoard(R, M);
                }
                else
                {
                    board = GetBoard(R, C, M);
                }
                
                sw.Write("Case #{0}: ", i + 1);
                sw.WriteLine();
                if (board == null)
                {
                    sw.Write("Impossible");
                    numImpossible++;
                    sw.WriteLine();
                }
                else
                {
                    for (int j = 0; j < R; j++)
                    {
                        for (int k = 0; k < C; k++)
                        {
                            sw.Write(board[j, k]);
                        }
                        sw.WriteLine();
                    }
                }
                

            }
            sw.Close();
        }

        static char[,] GetSingleRowBoard(int C, int M)
        {
            if (M >= C - 1) return null;

            char[,] board = new char[1, C];
            board[0,0]='c';
            for (int j = 1; j < C; j++)
            {
                if (j + M < C)
                {
                    board[0, j] = '.';
                }
                else
                {
                    board[0, j] = '*';
                }
            }

            return board;
        }

        static char[,] GetSingleColumnBoard(int R, int M)
        {
            if (M >= R - 1) return null;

            char[,] board = new char[R, 1];
            board[0, 0] = 'c';
            for (int j = 1; j < R; j++)
            {
                if (j + M < R)
                {
                    board[j, 0] = '.';
                }
                else
                {
                    board[j, 0] = '*';
                }
            }

            return board;
        }
        
        static char[,] GetDoubleRowBoard(int C, int M)
        {
            if (M > 2 * C - 4) return null;
            if (M % 2 == 1) return null;

            char[,] board = new char[2, C];
            board[0, 0] = 'c';
            board[1, 0] = '.';

            for (int j = 1; j < C; j++)
            {
                if (j + M/2 < C)
                {
                    board[0, j] = '.';
                    board[1, j] = '.';
                }
                else
                {
                    board[0, j] = '*';
                    board[1, j] = '*';
                }
            }

            return board;
        }

        static char[,] GetDoubleColumnBoard(int R, int M)
        {
            if (M > 2 * R - 4) return null;
            if (M % 2 == 1) return null;

            char[,] board = new char[R, 2];
            board[0, 0] = 'c';
            board[0, 1] = '.';

            for (int j = 1; j < R; j++)
            {
                if (j + M / 2 < R)
                {
                    board[j, 0] = '.';
                    board[j, 1] = '.';
                }
                else
                {
                    board[j, 0] = '*';
                    board[j, 1] = '*';
                }
            }
            return board;
        }
        static char[,] GetBoard(int R,int C, int M)
        {
            int numClean = R * C - M;
            if (numClean < 4 || numClean == 5 || numClean == 7) return null;

            char[,] board = new char[R, C];

            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    board[j, k] = '*';
                }
            }

            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    board[j, k] = '.';
                    numClean--;
                }
            }

            for (int j = 2; j < R||j<C; j++)
            {
                if (numClean >= 2)
                {
                    if (j < R)
                    {
                        board[j, 0] = '.';
                        board[j, 1] = '.';
                        numClean -= 2;
                    }
                }
                else
                {
                    break;
                }

                if (numClean >= 2)
                {
                    if (j < C)
                    {
                        board[0, j] = '.';
                        board[1, j] = '.';
                        numClean -= 2;
                    }
                }
                else
                {
                    break;
                }
            }

            

            for (int j = 2; j < R; j++)
            {
                for (int k = 2; k < C; k++)
                {
                    if (numClean > 0)
                    {
                        board[j, k] = '.';
                        numClean--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (numClean == 0) break;
            }

            board[0, 0] = 'c';
            return board;
        }
    }
}
