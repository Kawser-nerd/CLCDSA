using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        bool[] isHolding = new bool[9];
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            string s = Console.ReadLine();
            for (int j = 0; j < s.Length; j++)
            {
                if (isHolding[j])
                {
                    if (s[j] != 'o')
                    {
                        isHolding[j] = false;
                    }
                }
                else
                {
                    if (s[j] == 'o')
                    {
                        res++;
                        isHolding[j] = true;
                    }
                }
                if (s[j] == 'x')
                {
                    res++;
                }
            }
        }
        Console.WriteLine(res);
    }
}