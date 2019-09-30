using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r2
{
    class Program
    {
        static long ans;
        static bool poss;
        static void Main(string[] args)
        {
            {
                string root = @"C:\GCJ\";
                string problem = "A";
                //string ptype = "small-attempt0";
                string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int R = int.Parse(line[0]);
                    int C = int.Parse(line[1]);
                    char[,] board = new char[R, C];
                    poss = true;
                    ans = 0;
                    for (int b = 0; b < R; b++)
                    {
                        string curLine = lines[idx++];
                        for (int c = 0; c < C; c++)
                        {
                            board[b, c] = curLine[c];
                        }
                    }
                    for (int b = 0; b < R; b++)
                    {
                        for (int c = 0; c < C; c++)
                        {
                            if (board[b, c] != '.' && board[b, c] != 'g')
                            {
                                calc(b, c, board);
                                if (!poss)
                                {
                                    break;
                                }
                            }
                        }
                        if (!poss)
                        {
                            break;
                        }
                    }

                    tw.WriteLine("Case #{0}: {1}", a + 1, (poss ? ans.ToString() : "IMPOSSIBLE"));
                }

                tw.Close();
            }
        }

        private static void calc(int row, int col, char[,] board)
        {
            int curSize = 1;
            int r = row;
            int c = col;
            char direction = board[r, c];
            board[r, c] = 'g';

            HashSet<char> orig = new HashSet<char>();
            orig.Add(direction);
            bool retry = false;

            bool done = false;
            while (!done)
            {
                if (retry)
                {
                    if (orig.Count == 1)
                    {
                        ans++;
                    }
                    r = row;
                    c = col;
                    if(!orig.Contains('>')){
                        direction = '>';
                    }else if(!orig.Contains('<')){
                        direction = '<';
                    }
                    else if (!orig.Contains('^'))
                    {
                        direction = '^';
                    }
                    else if (!orig.Contains('v'))
                    {
                        direction = 'v';
                    }
                    else
                    {
                        poss = false;
                        break;
                    }
                    orig.Add(direction);
                }
                retry = false;
                bool edge = false;
                if (direction == '>')
                {
                    if (c < board.GetLength(1) - 1)
                    {
                        c++;
                    }
                    else
                    {
                        edge = true;
                    }
                }
                else if (direction == '<')
                {
                    if (c > 0)
                    {
                        c--;
                    }
                    else
                    {
                        edge = true;
                    }
                }
                else if (direction == '^')
                {
                    if (r > 0)
                    {
                        r--;
                    }
                    else
                    {
                        edge = true;
                    }
                }
                else if (direction == 'v')
                {
                    if (r < board.GetLength(0) -1)
                    {
                        r++;
                    }
                    else
                    {
                        edge = true;
                    }
                }

                if (edge)
                {
                    if (curSize == 1)
                    {
                        retry = true;
                    }
                    else
                    {
                        ans++;
                        done = true;
                    }
                }
                else
                {
                    if (board[r, c] == 'g')
                    {
                        done = true;
                    }
                    else if (board[r, c] != '.')
                    {
                        direction = board[r, c];
                        board[r, c] = 'g';
                        curSize++;
                    }
                }
            }
            //board[b, c] = 'g';

        }
    }
}
