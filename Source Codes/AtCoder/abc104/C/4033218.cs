using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int D = int.Parse(s[0]);
            int G = int.Parse(s[1]);
            List<int[]> list = new List<int[]>();
            for(int i = 0; i < D; i++)
            {
                int[] xz = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                list.Add(xz);
            }

            int min = int.MaxValue;
            int n = (int)Math.Pow(2, D);
            for (int i = 0; i < n; i++)
            {
                int k = i, counter = 0, countProblems = 0;
                int sum = 0;
                List<int> plist = new List<int>();
                while (counter < D)
                {
                    int[] v = list[counter];
                    if (k % 2 == 1)
                    {
                        sum += v[0] * (counter + 1) * 100 + v[1];
                        countProblems += v[0];
                    }
                    else
                    {
                        plist.AddRange(Enumerable.Repeat((counter + 1) * 100, v[0] - 1));
                    }
                    k /= 2;
                    counter++;

                }
                plist.Reverse();
                if (sum < G)
                {
                    foreach (int p in plist)
                    {
                        sum += p; countProblems++;
                        if (sum >= G) break;
                    }
                }
                if (sum >= G && countProblems < min) min = countProblems;
            }
            Console.WriteLine(min);

        }
    }
}