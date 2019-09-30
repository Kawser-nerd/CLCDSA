using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();

        int i = 0;
        while (i < s.Length - 4)
        {
            string subs = s.Substring(i, 5);
            if (subs == "dream")
            {
                i += 5;
                if (i < s.Length - 1 && s.Substring(i, 2) == "er")
                {
                    if (!(i < s.Length - 2 && s.Substring(i, 3) == "era"))
                    {
                        i += 2;
                    }
                }
            }
            else if (subs == "erase")
            {
                i += 5;
                if (i < s.Length && s.Substring(i, 1) == "r") i++;
            }
            else
            {
                break;
            }
        }
        if (i == s.Length)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
        //Main();
    }
}