using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var S = Console.ReadLine();
        var hash = new HashSet<char> { 'A','C','G','T' };
        int max = 0;
        for(int i = 0; i < S.Length; i++)
        {
            int len = 0;
            for(int j = i; j < S.Length; j++)
            {
                if (!hash.Contains(S[j]))
                {
                    break;
                }
                len++;
            }
            max = Math.Max(max, len);
        }

        Console.WriteLine(max);
    }

}