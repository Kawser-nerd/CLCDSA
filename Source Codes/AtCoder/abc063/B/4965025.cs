using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Math;


namespace AtCodeeeer
{
    class AtCOOOOOOOOOOOder
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            List<string> ls = new List<string>();
            string ans = "yes";
            for (int i = 0; i < s.Length; i++)
            {
                if (ls.Contains(s[i].ToString()) == false)
                {
                    ls.Add(s[i].ToString());
                }
                else
                {
                    ans = "no";
                }
            }
            WriteLine(ans);
        }
    }
}