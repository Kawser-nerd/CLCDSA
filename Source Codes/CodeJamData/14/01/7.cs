using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

class MagicTrick
{
    public void Solve()
    {
        StreamReader sr = new StreamReader(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\A.in");
        StreamWriter sw = new StreamWriter(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\A.out");

        int test_cases = Int32.Parse(sr.ReadLine());
        for (int t = 1; t <= test_cases; t++)
        {
            List<int> first = new List<int>();
            List<int> second = new List<int>();
            List<int> intersection = new List<int>();

            // Input information
            int first_row = Int32.Parse(sr.ReadLine());
            for (int i = 1; i <= 4; i++)
            {
                string line = sr.ReadLine();
                if (i == first_row)
                {
                    for (int j = 0; j < 4; j++)
                        first.Add(Int32.Parse(line.Split()[j]));
                }
            }

            int second_row = Int32.Parse(sr.ReadLine());
            for (int i = 1; i <= 4; i++)
            {
                string line = sr.ReadLine();
                if (i == second_row)
                {
                    for (int j = 0; j < 4; j++)
                        second.Add(Int32.Parse(line.Split()[j]));
                }
            }

            // Find intersection of the two lists
            intersection = first.Intersect(second).ToList();

            // Output
            string answer = "";
            if (intersection.Count == 1) answer = intersection[0].ToString();
            else if (intersection.Count == 0) answer = "Volunteer cheated!";
            else answer = "Bad magician!";
            string output = String.Format("Case #{0}: {1}", t, answer);

            Console.WriteLine(output);
            sw.WriteLine(output);
        }

        sr.Close();
        sw.Close();
    }
}
