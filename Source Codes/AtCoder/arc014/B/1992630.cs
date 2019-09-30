using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<string> wordList = new List<string>();
        char lastChar = ' ';
        for (int i = 0; i < n; i++)
        {
            string s = Console.ReadLine();
            if (wordList.Contains(s) || (lastChar != s[0] && i != 0))
            {
                Console.WriteLine(i % 2 == 1 ? "WIN" : "LOSE");
                return;
            }
            wordList.Add(s);
            lastChar = s.Last();
        }
        Console.WriteLine("DRAW");

    }
}