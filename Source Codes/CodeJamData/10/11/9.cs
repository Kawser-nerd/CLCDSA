using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1AA
{
    class Program
    {
        static void Main(string[] args)
        {            //FileStream stream = new FileStream(@"C:\Users\taniguchi\Documents\Downloads\A-large.in", FileMode.Open);
            //StreamReader reader = new StreamReader(stream);

            TextReader reader = Console.In;

            int T = int.Parse(reader.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string line = reader.ReadLine();
                int N = int.Parse(line.Split()[0]);
                int K = int.Parse(line.Split()[1]);

                char[,] board = new char[N, N];
                for (int i = 0; i < N; i++)
                {
                    line = reader.ReadLine();
                    for (int j = 0; j < N; j++)
                    {
                        board[i, j] = line[j];
                    }
                }


                board = rotate(board, N);
                board = gravity(board, N);

                //debugPrint(board, N);

                bool red = isWiner(board, N, K, 'R');
                bool blue = isWiner(board, N, K, 'B');

                string result = "Neither";
                if (red && blue)
                    result = "Both";
                else if (red)
                    result = "Red";
                else if (blue)
                    result = "Blue";

                Console.WriteLine("Case #{0}: {1}", t + 1, result);
            }
        }

        static void debugPrint(char[,] board, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    Console.Write(board[i, j]);
                Console.WriteLine();
            }
        }

        static char[,] rotate(char[,] board, int n)
        {
            char[,] ret = new char[n, n];

            for(int i = 0;i < n;i++)
                for (int j = 0; j < n; j++)
                {
                    ret[i, j] = board[n - j - 1, i];
                }
            return ret;
        }

        static char[,] gravity(char[,] board, int n)
        {
            char[,] ret = new char[n, n];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    ret[i, j] = '.';

            
            for (int i = 0; i < n; i++)
            {
                //各列のピースを下から保存
                int k = n;
                for (int j = n-1; j >= 0; j--)
                    if (board[j, i] != '.')
                        ret[--k, i] = board[j, i];
            }
            return ret;
        }

        static bool isWiner(char[,] board, int n, int k,char c)
        {
            //tate
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (board[j, i] == c)
                    {
                        if (++count == k)
                            return true;
                    }
                    else if (board[j, i] == '.')
                    {
                        continue;
                    }
                    else
                        count = 0;
                }
            }
            //yoko
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if (board[i, j] == c)
                    {
                        if (++count == k)
                            return true;
                    }
                    else
                    {
                        count = 0;
                    }
                }
            }
            //naname1
            for (int i = 0; i < 2 * n; i++)
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i - j < 0) break;
                    if (i - j >= n) continue;

                    if (board[i - j, j] == c)
                    {
                        if (++count == k)
                            return true;
                    }
                    else
                        count = 0;
                }
            }
            //naname2

            for (int i = -n; i < n; i++)
            {
                int count = 0;
                for (int j = 0; i + j < n && j < n; j++)
                {
                    if (i + j < 0) continue;

                    if (board[i + j, j] == c)
                    {
                        if (++count == k)
                            return true;
                    }
                    else
                        count = 0;
                }
            }

            return false;
        }

    }
}
