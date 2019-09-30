using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJ1A2
{
    class Program
    {
        static void Main(string[] args)
        {
            const string file = "C:\\Jam\\B-large";
            StreamReader sr = new StreamReader(file + ".in");
            StreamWriter sw = new StreamWriter(file + ".out");
            int ti, t;
            t = int.Parse(sr.ReadLine());
            for (ti = 1; ti <= t; ti++)
            {
                string[] inp = sr.ReadLine().Split(' ');
                int n, p;
                n = int.Parse(inp[0]);
                p = int.Parse(inp[1]);

                int[] rec = new int[n];
                inp = sr.ReadLine().Split(' ');
                for (int i = 0; i < n; i++)
                    rec[i] = int.Parse(inp[i]);

                int[,] a = new int[n, p];
                int[] tinp = new int[p];
                for (int i = 0; i < n; i++)
                {
                    inp = sr.ReadLine().Split(' ');
                    for (int j = 0; j < p; j++)
                    {
                        tinp[j] = int.Parse(inp[j]);
                    }
                    Array.Sort(tinp);
                    for (int j = 0; j < p; j++)
                    {
                        a[i, j] = tinp[j];
                    }
                }

                int[,] amax = new int[n, p];
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < p; j++)
                    {
                        amax[i,j] = a[i, j] * 10 / (9 * rec[i]);
                    }
                }

                int[,] amin = new int[n, p];
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < p; j++)
                    {
                        amin[i, j] = (int)Math.Ceiling((double)(a[i, j] * 10) / (11 * rec[i]));
                    }
                }

                int kit = 0;

                for (int k = 0; k < p; k++)
                {
                    if (amax[0, k] != 0)
                    {
                        for(int v = amin[0,k]; v <=amax[0,k]; v++)
                        {
                            bool rem = true;
                            for (int i = 1; i < n; i++)
                            {
                                bool pos = false;
                                for (int j = 0; j < p; j++)
                                {
                                    if (amin[i,j] <= v && v<= amax[i,j])
                                    {
                                        pos = true;
                                        break;
                                    }
                                }
                                if (!pos)
                                {
                                    rem = false;
                                    break;
                                }
                            }

                            if (rem)
                            {
                                kit++;
                                for (int i = 1; i < n; i++)
                                {
                                    for (int j = 0; j < p; j++)
                                    {
                                        if(amin[i, j] <= v && v <= amax[i, j])
                                        {
                                            amin[i, j] = int.MaxValue;
                                            amax[i, j] = int.MinValue;
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }

                sw.WriteLine("Case #{0}: {1}", ti, kit);
                Console.WriteLine(ti);
            }
            sw.Dispose();
            sr.Dispose();
        }
    }
}