using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
        static int go(int[] values, int[] gates, int[] changeable, int m, int v,int at)
        {
            bool child = at * 2 > m;
            if (child)
            {
                if (values[at] == v)
                {
                    return 0;
                }
                else
                {
                    return 999999999;
                }
            }
            else
            {
                int andCost = 0;
                if (v == 0)
                {
                    andCost = Math.Min(go(values, gates, changeable, m, 0, at * 2), go(values, gates, changeable, m, 0, at * 2 + 1));
                }
                else
                {
                    andCost = go(values, gates, changeable, m, 1, at * 2) + go(values, gates, changeable, m, 1, at * 2 + 1);
                }

                int orCost = 0;

                if (v == 0)
                {
                    orCost = go(values, gates, changeable, m, 0, at * 2) + go(values, gates, changeable, m, 0, at * 2 + 1);
                    
                }
                else
                {
                    orCost = Math.Min(go(values, gates, changeable, m, 1, at * 2), go(values, gates, changeable, m, 1, at * 2 + 1));
                }

                int totalCost = 0;
                if (changeable[at] == 1)
                {
                    if (gates[at] == 0)
                    {
                        totalCost = Math.Min(orCost, andCost + 1);
                    }
                    else
                    {
                        totalCost = Math.Min(orCost + 1, andCost);
                    }
                }
                else
                {
                    if (gates[at] == 0)
                    {
                        totalCost = orCost;
                    }
                    else
                    {
                        totalCost = andCost;
                    }
                }
                return totalCost;
            }
        }
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("A-large.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                string[] line = input[lineAt++].Split(' ');
                int m, v;
                m = int.Parse(line[0]);
                v = int.Parse(line[1]);

                int[] values = new int[m+1];
                int[] gates = new int[m+1];
                int[] changeable = new int[m+1];
                for (int j = 1; j <= m; j++)
                {
                    if (j <= (m - 1) / 2)
                    {
                        line = input[lineAt++].Split(' ');
                        gates[j] = int.Parse(line[0]);
                        changeable[j] = int.Parse(line[1]);
                    }
                    else
                    {
                        values[j] = int.Parse(input[lineAt++]);
                    }
                }
                int res = go(values, gates, changeable, m, v, 1);
                string num;
                if (res > m)
                {
                    num = "IMPOSSIBLE";
                }
                else
                {
                    num = res.ToString();
                }
                output += "Case #" + (i + 1) + ": " + num + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
