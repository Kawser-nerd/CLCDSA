using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{
    static string S = Console.ReadLine();
    static string[] M = new string[] { "dream", "dreamer", "erase", "eraser" };
    static void Main()
    {
        string s = "";
        int cnt = 0;
     for(int i = S.Length - 1; i >= 0; i--)
        {
            s = S[i] + s;
            cnt++;
            if (cnt > 7)
            {
                Console.WriteLine("NO");
                return;
            }
            if (cnt == 5)
            {
                if (s == "dream" || s == "erase")
                {
                    cnt = 0;
                    s = "";
                }
            }
            if (cnt == 6)
            {
                if (s == "eraser")
                {
                    cnt = 0;
                    s = "";
                }
            }
            if (cnt == 7)
            {
                if (s == "dreamer")
                {
                    cnt = 0;
                    s = "";
                }
            }
        }
        if (cnt == 0)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}