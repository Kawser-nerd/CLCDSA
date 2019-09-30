using System;
using System.Collections.Generic;

namespace AtTest.AGC026
{
    class C
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            string left = "";
            string right = "";

            for (int i = 0; i < n; i++)
            {
                left += s[i];
                right += s[2 * n - i - 1];
            }

            var patMapR = new Dictionary<string, Dictionary<string, long>>();
            int allPat = (int)Math.Pow(2, n);
            for (int i = 0; i < allPat; i++)
            {
                var strs = new string[2];
                strs[0] = "";
                strs[1] = "";
                for (int sI = 0; sI < n; sI++)
                {
                    if ((i >> sI & 1) == 1)
                    {
                        strs[0] += right[sI];
                    }
                    else
                    {
                        strs[1] += right[sI];
                    }
                }

                if (patMapR.ContainsKey(strs[0]))
                {
                    if (patMapR[strs[0]].ContainsKey(strs[1]))
                    {
                        patMapR[strs[0]][strs[1]]++;
                    }
                    else
                    {
                        patMapR[strs[0]].Add(strs[1], 1);
                    }
                }
                else
                {
                    patMapR.Add(strs[0], new Dictionary<string, long>());
                    patMapR[strs[0]].Add(strs[1], 1);
                }
            }

            long patterns = 0;
            for (int i = 0; i < allPat; i++)
            {
                var patL = new string[2];
                patL[0] = "";
                patL[1] = "";
                for (int sI = 0; sI < n; sI++)
                {
                    if ((i >> sI & 1) == 1)
                    {
                        patL[0] += left[sI];

                    }
                    else
                    {
                        patL[1] += left[sI];
                    }
                }
                if (patMapR.ContainsKey(patL[0])&&patMapR[patL[0]].ContainsKey(patL[1]))
                {
                    patterns += patMapR[patL[0]][patL[1]];
                }
            }

            Console.WriteLine(patterns);
        }
    }
}