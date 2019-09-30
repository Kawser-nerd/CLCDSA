using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace MagicTrick
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("D:\\A-small-attempt0.out");

            //StreamReader sr = new StreamReader("D:\\C-large-practice.in");
            //StreamWriter sw = new StreamWriter("D:\\C-large-practice.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {
                string[] str = sr.ReadLine().Split(' ');

                int[,] set1 = new int[4, 4];
                int[,] set2 = new int[4, 4];

                int ans1 = Convert.ToInt32(str[0])-1;

                for (int j = 0; j < 4; j++)
                {
                    str = sr.ReadLine().Split(' ');
                    for (int k = 0; k < 4; k++)
                    {
                        set1[j, k] = Convert.ToInt32(str[k]);
                    }
                }

                str = sr.ReadLine().Split(' ');

                int ans2 = Convert.ToInt32(str[0]) - 1;

                for (int j = 0; j < 4; j++)
                {
                    str = sr.ReadLine().Split(' ');
                    for (int k = 0; k < 4; k++)
                    {
                        set2[j, k] = Convert.ToInt32(str[k]);
                    }
                }

                List<int> possible = new List<int>();

                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (set1[ans1, j] == set2[ans2, k])
                        {
                            possible.Add(set1[ans1, j]);
                        }
                    }
                }

                sw.Write("Case #{0}: ", i + 1);
                if (possible.Count == 0)
                {
                    sw.Write("Volunteer cheated!");
                }
                else if (possible.Count == 1)
                {
                    sw.Write(possible[0]);
                }
                else
                {
                    sw.Write("Bad magician!");
                }
                sw.WriteLine();

            }
            sw.Close();
        }

    }
}
