using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            int tst = int.Parse(Console.ReadLine());
            for (int cas = 0; cas < tst; cas++)
            {
                string s = Console.ReadLine();
                string[] tokens = s.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int R = int.Parse(tokens[0]);
                int C = int.Parse(tokens[1]);
                int[,] alt = new int[R,C];
                for (int i = 0; i < R; i++)
                {
                    s = Console.ReadLine();
                    tokens = s.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    for (int j = 0; j < C; j++)
                    {
                        alt[i, j] = int.Parse(tokens[j]);
                    }
                }
                int[] dr = {-1, 0, 0, 1};
                int[] dc = {0, -1, 1, 0};
                char[][] result = new char[R][];
                for (int i = 0; i < R; i++)
                {
                    result[i] = new char[C];
                    for (int j = 0; j < C; j++)
                    {
                        result[i][j] = 'A';
                    }
                }
                char cur = 'a';
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (result[i][j]!='A')
                        {
                            continue;
                        }
                        List<KeyValuePair<int,int>> l = new List<KeyValuePair<int, int>>();
                        int cr = i;
                        int cc = j;
                        while (cr!=-1&&result[cr][cc]=='A')
                        {
                            int rr = -1;
                            int rc = -1;
                            for (int k = 0; k < 4; k++)
                            {
                                int tr = cr + dr[k];
                                int tc = cc + dc[k];
                                if (tr<0||tr>=R)
                                {
                                    continue;
                                }
                                if (tc<0||tc>=C)
                                {
                                    continue;
                                }
                                if (alt[tr,tc]<alt[cr,cc])
                                {
                                    if (rr==-1)
                                    {
                                        rr = tr;
                                        rc = tc;
                                    }
                                    else if (alt[tr,tc]<alt[rr,rc])
                                    {
                                        rr = tr;
                                        rc = tc;
                                    }
                                }
                            }
                            l.Add(new KeyValuePair<int, int>(cr,cc));
                            cr = rr;
                            cc = rc;
                        }
                        if (cr==-1)
                        {
                            foreach (var pair in l)
                            {
                                result[pair.Key][pair.Value] = cur;
                            }
                            cur = (char) (cur + 1);
                        }
                        else
                        {
                            
                            foreach (var pair in l)
                            {
                                result[pair.Key][pair.Value] = result[cr][cc];
                            }
                        }
                    }
                }
                Console.WriteLine("Case #"+(cas+1)+":");
                for (int i = 0; i < R; i++)
                {
                    string line = "";
                    for (int j = 0; j < C; j++)
                    {
                        if (j>0)
                        {
                            line = line + " ";
                        }
                        line = line + result[i][j];
                    }
                    Console.WriteLine(line);
                }

            }
        }
    }
}
