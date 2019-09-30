using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var S = Console.ReadLine();
        var subStrs = new HashSet<char>() { 'A', 'C', 'G', 'T' };

        int maxLen = 0;
        for (int i = 0; i < S.Length; i++)
        {
            for(int subLen = S.Length - i; i < subLen ; subLen--)
            {
                var sub = S.Substring(i, subLen);
                int count = 0;
                foreach (var ch in sub)
                {
                    if (subStrs.Contains(ch))
                    {
                        count++;
                        if(maxLen < count)
                        {
                            maxLen = count;
                        }
                    }
                    else
                    {
                        count = 0;
                        continue;
                    }
                }

            }
        }

        Console.WriteLine(maxLen);
    }
}