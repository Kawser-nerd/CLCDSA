using System;
using System.Linq;
using System.Collections.Generic;
 
class P
{
    static void Main()
    {
        string s = Console.ReadLine() + "+";
        bool contain0 = false;
        int res = 0;
        for (int i = 0; i < s.Length; i += 2)
        {
            if (s[i] == '0') contain0 = true;
            if(s[i + 1] == '+')
            {
                if (!contain0) res++;
                contain0 = false;
            }
        }
        Console.WriteLine(res);
    }
}