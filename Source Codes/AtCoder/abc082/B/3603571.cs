using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Two Anagrams
            string s = Console.ReadLine();
            string t = Console.ReadLine();

            string sortedS = SortCharacters(s);
            string sortedT = SortCharacters(t, true);

            if (String.Compare(sortedT, sortedS) > 0)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }

        static string SortCharacters(string s, bool isDescending = false)
        {
            var chars = s.ToCharArray();
            var query = new List<char>();
            
            if (!isDescending)
            {
                query = chars.OrderBy(c => c).ToList();
            }
            else
            {
                query = chars.OrderByDescending(c => c).ToList();
            }

            return String.Join("", query);
        }
    }
}