using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C025
    {

        static Dictionary<string, int[]> scores = new Dictionary<string, int[]>();
        static int[,] b = new int[2, 3], c = new int[3, 2];

        static string GetString(char[,] board)
        {
            string s="";
            foreach(char bc in board)
            {
                s += bc;
            }
            return s;
        }

        static void PutNew(int turnNo, char[,] board)
        {
            if (turnNo == 10)
            {
                string sfinal = GetString(board);
                scores[sfinal] = GetScore(board);
                return;
            }


            int imax = -1, jmax = -1;
            int max = -1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i, j] == '.')
                    {
                        char[,] bn = (char[,])board.Clone();
                        if (turnNo % 2 == 1) bn[i, j] = '+';
                        else bn[i, j] = '*';
                        string str = GetString(bn);
                        if (!scores.ContainsKey(str))
                        {
                            PutNew(turnNo + 1, bn);
                        }
                        int[] score0 = scores[str];
                        int score = turnNo % 2 == 1 ? score0[0] : score0[1];
                        if (score > max)
                        {
                            imax = i; jmax = j; max = score;
                        }
                    }
                }
            }

            char[,] bm = (char[,])board.Clone();
            bm[imax, jmax] = turnNo % 2 == 1 ? '+' : '*';
            string saft = GetString(bm);
            string sbfr = GetString(board);

            scores[sbfr] = scores[saft];
        }

        static int[] GetScore(char[,] board)
        {
            int x = 0, y = 0;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    if (board[i, j] == board[i, j + 1]) x += c[i, j];
                    else y += c[i, j];
                }
            }
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i, j] == board[i+1, j]) x += b[i, j];
                    else y += b[i, j];
                }
            }
            return new int[] { x, y };
        }

        static void Main(string[] args)
        {
            int[] b1 = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
            int[] b2 = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
            int[] c1 = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
            int[] c2 = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
            int[] c3 = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();

            for(int i = 0; i < 3; i++)
            {
                b[0, i] = b1[i]; b[1, i] = b2[i];
            }
            for(int i = 0; i < 2; i++)
            {
                c[0, i] = c1[i]; c[1, i] = c2[i]; c[2, i] = c3[i];
            }

            char[,] board = new char[3, 3];
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    board[i, j] = '.';
                }
            }

            PutNew(1, board);
            string s = GetString(board);
            int[] sc = scores[s];
            Console.WriteLine(sc[0]);
            Console.WriteLine(sc[1]);
        }

    }
}