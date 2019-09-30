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
        for(int startIndex = 0; startIndex < S.Length; startIndex++)
        {
            int count = 0;
            for(int i = startIndex; i < S.Length; i++)
            {
                if (!subStrs.Contains(S[i]))
                {
                    break;
                }

                count++;
            }
            maxLen = Math.Max(maxLen, count);
        }

        Console.WriteLine(maxLen);
    }
}