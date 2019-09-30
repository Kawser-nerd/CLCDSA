using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{

    class Program
    {

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            StringBuilder b = new StringBuilder();
            int n = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < n; i++)
            {
                b.AppendFormat("Case #{0}: ", i +1);

                int number = int.Parse(lines[index++]);
                List<string> results = new List<string>();
               
                for (int j = 0; j < number; j++)
                {
                    results.Add(lines[index++]);
                }
                // WP
                List<double> wp = new List<double>();
                List<int> plays = new List<int>();
                List<int> wins = new List<int>();
                List<int> loses = new List<int>();
                for (int j = 0; j < number; j++)
                {
                    int win = results[j].Where(c => c == '1').Count();
                    int lose = results[j].Where(c => c == '0').Count();
                    plays.Add(win + lose);
                    wp.Add(((double)win) / ((double)(win + lose)));
                    wins.Add(win);
                    loses.Add(lose);
                }
                List<double> owp = new List<double>();
                for (int j = 0; j < number; j++)
                {
                    double total = 0.0;
                    int count = 0;
                    for (int k = 0; k < number; k++)
                    {
                        if (k != j && results[j][k] != '.')
                        {
                            count++;
                            if (results[k][j] == '.')
                            {
                                total += wp[k];
                            }
                            else
                            {
                                int newTotal = plays[k] - 1;
                                double score = wins[k];
                                if (results[k][j] == '1')
                                {
                                    score -= 1.0;
                                }
                                total += score / newTotal;
                            }
                        }
                    }
                    owp.Add(total / Math.Max(1, count));
                }
                List<double> oowp = new List<double>();
                for (int j = 0; j < number; j++)
                {
                    double total = 0.0;
                    int count = 0;
                    for (int k = 0; k < number; k++)
                    {
                        if (k != j && results[j][k] != '.')
                        {
                            count++;
                            total += owp[k];
                        }
                    }
                    oowp.Add(total / Math.Max(1, count));
                }
                b.AppendLine("");
                for (int j = 0; j < number; j++)
                {
                    double rpi = 0.25 * wp[j] + 0.5 * owp[j] + 0.25 * oowp[j];
                    b.AppendLine(rpi.ToString());
                }

            }
            File.WriteAllText(args[0] + ".out", b.ToString());
        }
    }
}
