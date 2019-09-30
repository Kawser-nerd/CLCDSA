using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        int res = 0;
        int padL = 0;
        int padR = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == '(')
            {
                res--;
            }
            else
            {
                res++;
                if (res > 0)
                {
                    padL += res;
                    res = 0;
                }
            }
        }
        padR = -res;
        Console.Write(string.Join("", Enumerable.Repeat('(', padL).ToArray()));
        Console.Write(s);
        Console.Write(string.Join("", Enumerable.Repeat(')', padR).ToArray()));
        Console.WriteLine();
    }
}