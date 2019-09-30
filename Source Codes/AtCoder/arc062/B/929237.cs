using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main(string[] args)
    {
        string s = Console.ReadLine();
        int score = 0;
        for (int i = 0; i < s.Length; ++i)
        {
            if ((i & 1) == 0)
            {
                score += s[i] == 'g' ? 0 : -1;
            }
            else
            {
                score += s[i] == 'g' ? 1 : 0;
            }
        }
        Console.WriteLine(score);
    }
}