using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("B-large.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                string[] line = input[lineAt++].Split(' ');
                int n, m, a;
                n = int.Parse(line[0]);
                m = int.Parse(line[1]);
                a = int.Parse(line[2]);

                string res = "IMPOSSIBLE";
                bool solved = false;
                
                for (int x = 1; x <= n; x++)
                {
                    if (a / x * x == a && (a/x) <= m)
                    {
                        res = "0 0 " + x + " " + "0" + " " + "0" + " " + (a/x);
                        solved = true;
                        break;
                    }
                }

                if (!solved)
                {
                    for (int y = 1; y <= m; y++)
                    {
                        if (a / y * y == a && (a/y) <= n)
                        {
                            res = "0 0 " + "0" + " " + y + " " + (a/y) + " " + "0";
                            solved = true;
                            break;
                        }
                    }
                }

                if(!solved)
                {
                    for (int x = 1; x <= n; x++)
                    {
                        int min = a / x;
                        for (int yy = min; yy <= m; yy++)
                        {
                            int first = x * yy;
                            if (first < a)
                            {
                                continue;
                            }
                            int diff = first - a;
                            int xx = 0;
                            int y = 0;
                            if(diff == 0)
                            {
                                res = "0 0 " + x + " " + y + " " + xx + " " + yy;
                                solved = true;
                            }
                            else
                            {
                                for (int d = 1; d <= diff; d++)
                                {
                                    if (diff / d * d == diff)
                                    {
                                        int other = diff / d;
                                        if (d <= n && other <= m)
                                        {
                                            xx = d;
                                            y = other;
                                        }
                                        else if (d <= m && other <= n)
                                        {
                                            xx = other;
                                            y = d;
                                        }
                                        else
                                        {
                                            continue;
                                        }

                                        res = "0 0 " + x + " " + y + " " + xx + " " + yy;
                                        solved = true;
                                        break;
                                    }
                                }
                            }
                            if (solved) break;
                            //for (int y = 0; y <= m; y++)
                            //{
                            //    for (int xx = 0; xx <= n; xx++)
                            //    {
                            //        int cross = x * yy - xx * y;
                            //        if (cross == a)
                            //        {
                            //            res = "0 0 " + x + " " + y + " " + xx + " " + yy;
                            //            solved = true;
                            //        }
                            //    }
                            //}
                        }
                        if (solved) break;
                    }
                }

                output += "Case #" + (i + 1) + ": " + res + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
