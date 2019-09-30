/* To compile in MS Visual C# Express:
 * - create a new console program project
 * - import this file
 * - call Go()
 * 
 * Code Jam 2009
 * Author: Jack Hou (jack.m.hou@gmail.com)
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace CodeJam
{
    class AllYourBase
    {

        static public void Go()
        {
            string line = Console.ReadLine();
            int T = int.Parse(line);

            for (int t = 0; t < T; t++)
            {
                line = Console.ReadLine();

                char[] num = line.ToCharArray();

                Dictionary<char, int> cd = new Dictionary<char, int>();

                int k = 0;

                for (int i = 0; i < num.Length; i++)
                {
                    if (!cd.ContainsKey(num[i]))
                    {
                        if (k == 0)
                        {
                            cd.Add(num[i], 1);
                            k++;
                        }
                        else if (k == 1)
                        {
                            cd.Add(num[i], 0);
                            k++;
                        }
                        else
                        {
                            cd.Add(num[i], k);
                            k++;
                        }
                    }
                }

                if (k == 1) k = 2;

                int pow = 1;
                long result = 0;
                for (int i = 0; i < num.Length; i++)
                {
                    result += cd[num[num.Length - i - 1]] * pow;
                    pow *= k;
                }

                Console.WriteLine("Case #" + (t + 1) + ": " + result);
            }
        }

    }
}
