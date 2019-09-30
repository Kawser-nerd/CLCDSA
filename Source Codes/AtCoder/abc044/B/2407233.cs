using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string w = Console.ReadLine();
            bool beautiful = true;
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (w.Count(x => x == c) % 2 != 0) beautiful = false;
            }
            Console.WriteLine(beautiful ? "Yes" : "No");
        }
    }
}