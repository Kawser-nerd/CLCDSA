using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
        static int tostate(int r, int c, int px,int py,int pd)
        {
            Debug.Assert(r < 15 && r >= 0);
            Debug.Assert(c < 15 && c >= 0);
            Debug.Assert(px < 15 && px >= 0);
            Debug.Assert(py < 15 && py >= 0);
            Debug.Assert(pd < 5 && pd >= 0);
            return pd + py * 5 + px * 5 * 15 + c * 5 * 15 * 15 + r * 15 * 15 * 15 * 5;
        }
        static void fromstate(int state, out int r, out int c, out int px,out int py,out int pd)
        {
            pd = state % 5;
            state /= 5;
            py = state % 15;
            state /= 15;
            px = state % 15;
            state /= 15;
            c = state % 15;
            state /= 15;
            r = state;
        }
        
        static void Main(string[] args)
        {
            int[] dx = new int[] { 0, 0, -1, 1 };
            int[] dy = new int[] { -1, 1, 0, 0 };
            string[] input = File.ReadAllLines("B-large.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                string res = "THE CAKE IS A LIE";
                string[] line = input[lineAt++].Split(' ');
                int rows = int.Parse(line[0]);
                int cols = int.Parse(line[1]);
                string[] walls = new string[rows];
                int sr=0, sc=0;
                int cr=0, cc=0;
                for (int j = 0; j < rows; j++)
                {
                    walls[j] = input[lineAt++];
                    int t = walls[j].IndexOf('O');
                    if (t != -1)
                    {
                        sr = j;
                        sc = t;
                    }
                    t = walls[j].IndexOf('X');
                    if (t != -1)
                    {
                        cr = j;
                        cc = t;
                    }
                }

                int start = tostate(sr, sc, 0, 0, 4);
                Queue<int> q = new Queue<int>();
                q.Enqueue(start);
                bool[] dp = new bool[15*15*15*15*5];
                dp[start] = true;
                int turns = 0;
                do
                {
                    Queue<int> next = new Queue<int>();
                    while (q.Count > 0)
                    {
                        int r, c, px, py, pd;
                        fromstate(q.Dequeue(), out r, out c, out px,out py, out pd);
                        if (r == cr && c == cc)
                        {
                            res = turns.ToString();
                            next = new Queue<int>();
                            break;
                        }
                        else
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                int nr = r + dx[k];
                                int nc = c + dy[k];
                                if (nr < 0 || nr >= walls.Length || nc < 0 || nc >= walls[0].Length || walls[nr][nc] == '#')
                                {
                                    if (pd != 4)
                                    {
                                        // portal
                                        int nexts = tostate(px, py, r, c, k);
                                        if (!dp[nexts])
                                        {
                                            dp[nexts] = true;
                                            next.Enqueue(nexts);
                                        }
                                    }
                                }
                                else
                                {
                                    int nexts = tostate(nr, nc, px, py, pd);
                                     if (!dp[nexts])
                                    {
                                        dp[nexts] = true;
                                        next.Enqueue(nexts);
                                    }

                                    // shoot a portal
                                    do
                                    {
                                        nr += dx[k];
                                        nc += dy[k];
                                    } while (!(nr < 0 || nr >= walls.Length || nc < 0 || nc >= walls[0].Length || walls[nr][nc] == '#'));
                                    nr -= dx[k];
                                    nc -= dy[k];
                                    nexts = tostate(r, c, nr, nc, k);
                                    if (!dp[nexts])
                                    {
                                        dp[nexts] = true;
                                        q.Enqueue(nexts);
                                    }
                                }                                
                            }                               
                        }
                    }
                    turns++;
                    q = next;

                } while (q.Count > 0);
                


                output += "Case #" + (i + 1) + ": " + res + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
        static bool rock(int r, int c, int[] rr, int[] rc)
        {
            for (int i = 0; i < rr.Length; i++)
            {
                if (rr[i] == r && rc[i] == c) return true;
            }
            return false;
        }
    }
}
