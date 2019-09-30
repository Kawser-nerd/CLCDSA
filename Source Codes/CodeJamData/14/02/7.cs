using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

class CookieClicker
{
    public void Solve()
    {
        StreamReader sr = new StreamReader(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\B.in");
        StreamWriter sw = new StreamWriter(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\B.out");

        int test_cases = Int32.Parse(sr.ReadLine());
        for (int t = 1; t <= test_cases; t++)
        {
            string[] line = sr.ReadLine().Split();
            double C = Double.Parse(line[0]);
            double F = Double.Parse(line[1]);
            double X = Double.Parse(line[2]);

            double current_time = 0;
            double production = 2;
            double farm_payoff = C / F;
            double time_remaining;

            // Special case: Is the goal closer than a farm?
            if (X <= C)
            {
                string quick_answer = (X / 2).ToString();
                string quick_output = String.Format("Case #{0}: {1}", t, quick_answer);
                Console.WriteLine(quick_output);
                sw.WriteLine(quick_output);
                continue;
            }

            // We always start the loop with zero cookies
            for (; ; )
            {
                // Go to when we can afford a farm
                current_time += C / production;

                // At current rate, how long until the end?
                time_remaining = (X - C) / production;

                // If the end is closer than the farm payoff, we just go
                // to that time and exit. Otherwise, we build another farm
                if (time_remaining <= farm_payoff)
                {
                    current_time += time_remaining;
                    break;
                }
                else
                {
                    production += F;
                }
            }

            string answer = current_time.ToString();
            string output = String.Format("Case #{0}: {1}", t, answer);

            Console.WriteLine(output);
            sw.WriteLine(output);
        }

        sr.Close();
        sw.Close();
    }
}
