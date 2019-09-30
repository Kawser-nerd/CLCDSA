using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_026
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var subordinates = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                subordinates.Add(new List<int>());
            }
            for (int i = 1; i < n; i++)
            {
                int num = int.Parse(Console.ReadLine()) - 1;
                subordinates[num].Add(i);
            }

            var salaries = new long[n];
            for (int i = n - 1; i >= 0; i--)
            {
                salaries[i] = 1;
                long min = 0, max = 0;
                for (int j = 0; j < subordinates[i].Count; j++)
                {
                    if (min == 0 || salaries[subordinates[i][j]] < min)
                    {
                        min = salaries[subordinates[i][j]];
                    }
                    if (max == 0 || salaries[subordinates[i][j]] > max)
                    {
                        max = salaries[subordinates[i][j]];
                    }
                }
                salaries[i] += min + max;
            }
            Console.WriteLine(salaries[0]);
        }
    }
}