using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static Dictionary<char, int> rightChars = new Dictionary<char, int>();
        static List<char> bothChars = new List<char>();
        static int max = 0;

        static void Main(string[] args)
        {
            //[summary]B - Cut and Count
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            
            foreach (var c in s)
            {
                if (rightChars.ContainsKey(c))
                {
                    rightChars[c]++;
                }
                else
                {
                    rightChars.Add(c, 1);
                }                
            }

            for(int i = 0; i < n; i++)
            {
                MoveChars(s[i]);
            }

            Console.WriteLine(max);
        }

        static void MoveChars(char c)
        {
            if (rightChars[c] > 1)
            {
                rightChars[c]--;
            }
            else
            {
                rightChars.Remove(c);
            }

            if (rightChars.ContainsKey(c))
            {
                if (!bothChars.Contains(c))
                {
                    bothChars.Add(c);

                    if (bothChars.Count > max)
                    {
                        max = bothChars.Count;
                    }
                }
            }
            else
            {
                bothChars.Remove(c);
            }
        }
    }
}