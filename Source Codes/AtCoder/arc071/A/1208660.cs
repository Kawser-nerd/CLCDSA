using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dubious
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] totalCounts = new int[26];
            int[] counts = new int[26];
            String S;
            for (int i=0; i < n; i++)
            {
                S = Console.ReadLine();
                for (int j = 0; j < 26; j++)
                    counts[j] = 0;
                foreach (char c in S)
                {
                    counts[c - 'a']++; 
                }

                if (i == 0)
                {
                    for (int j = 0; j < 26; j++)
                        totalCounts[j] = counts[j];
                }
                else
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (counts[j] < totalCounts[j])
                            totalCounts[j] = counts[j];
                    }
                }

            }

            for(int j = 0; j < 26; j++)
            {
                for (int k = 0; k < totalCounts[j]; k++)
                    Console.Write((char)(j + 'a'));
            }
            Console.WriteLine();
        }
    }
}