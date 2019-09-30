using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJ1A1
{
    class Program
    {
        static void Main(string[] args)
        {
            const string file = "C:\\Jam\\A-large";
            StreamReader sr = new StreamReader(file + ".in");
            StreamWriter sw = new StreamWriter(file + ".out");
            int ti, t;
            t = int.Parse(sr.ReadLine());
            for (ti = 1; ti <= t; ti++)
            {
                string[] inp = sr.ReadLine().Split(' ');
                int r, c;
                r = int.Parse(inp[0]);
                c = int.Parse(inp[1]);
                char[,] g = new char[r, c];
                for(int i = 0;i<r; i++)
                {
                    string tline = sr.ReadLine();
                    for (int j = 0; j < c; j++)
                    {
                        g[i, j] = tline[j];
                    }
                }

                for (int i = 0; i < r; i++)
                {
                    char nonQ = '?';
                    for (int j = 0; j < c; j++)
                    {
                        if (g[i, j] != '?') {
                            nonQ = g[i, j];
                            break;
                        }
                    }
                    if(nonQ != '?')
                    {
                        for (int j = 0; j < c; j++)
                        {
                            if (g[i, j] == '?')
                            {
                                g[i, j] = nonQ;
                            } else
                            {
                                nonQ = g[i, j];
                            }
                        }
                    }
                }

                int l = -1;
                for(int i = 0; i<r; i++)
                {
                    if(g[i,0] != '?')
                    {
                        l = i;
                        break;
                    }
                }

                for (int i = 0; i < r; i++)
                {
                    if (g[i, 0] == '?')
                    {
                        for (int j = 0; j < c; j++)
                        {
                            g[i, j] = g[l, j];
                        }
                    } else
                    {
                        l = i;
                    }
                }

                sw.WriteLine("Case #{0}:", ti);
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        sw.Write(g[i, j]);
                    }
                    sw.WriteLine();
                }
                Console.WriteLine(ti);
            }
            sw.Dispose();
            sr.Dispose();
        }

    }
}
