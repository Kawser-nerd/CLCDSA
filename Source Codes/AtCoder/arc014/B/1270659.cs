using System;
using System.Collections.Generic;

namespace arc014_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            List<string> words = new List<string>();
            string a = Console.ReadLine();
            words.Add(a);
            bool end = false;
            for (int i = 1; i < n && !end; i++)
            {
                string b = Console.ReadLine();
                if (a[a.Length - 1] != b[0] || words.Contains(b))
                {
                    end = true;
                    Console.WriteLine(i % 2 == 0 ? "LOSE" : "WIN");
                }
                words.Add(b);
                a = b;
            }
            if (!end) Console.WriteLine("DRAW");
        }
    }
}