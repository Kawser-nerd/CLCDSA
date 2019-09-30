using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace DataPacking
{
    class Program
    {
        static void Main(string[] args)
        {

            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\A-small-attempt0.in");
            //StreamWriter sw = new StreamWriter("D:\\A-small-attempt0.out");

            StreamReader sr = new StreamReader("D:\\A-large.in");
            StreamWriter sw = new StreamWriter("D:\\A-large.out");


            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {

                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int N = Convert.ToInt32(str[0]);
                int CD_size = Convert.ToInt32(str[1]);

                List<int> sizes = new List<int>();
                str = sr.ReadLine().Split(' ');
                for (int j = 0; j < N; j++)
                {
                    sizes.Add(Convert.ToInt32(str[j]));
                }

                sizes.Sort();

                int numCDs = 0;
                while (sizes.Count > 0)
                {
                    if (sizes.Count == 1)
                    {
                        numCDs++;
                        sizes.RemoveAt(0);
                    }
                    else
                    {
                        numCDs++;
                        int rem = CD_size - sizes[sizes.Count - 1];
                        sizes.RemoveAt(sizes.Count - 1);

                        int tempIndex = -1;
                        for (int j = 0; j < sizes.Count; j++)
                        {
                            if (sizes[j] <= rem)
                            {
                                tempIndex = j;
                            }
                            else if (sizes[j] > rem)
                            {
                                break;
                            }
                        }

                        if (tempIndex >= 0)
                        {
                            sizes.RemoveAt(tempIndex);
                        }
                    }
                }

                sw.Write("Case #{0}: ", i + 1);

                sw.Write(numCDs);
               
                sw.WriteLine();
            }

            sr.Close();
            sw.Close();
        }
    }
}
