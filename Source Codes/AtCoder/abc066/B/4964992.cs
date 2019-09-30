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
            while (s.Length>1)
            {
                s = s.Remove(s.Length - 1, 1);
                if (s.Length % 2 == 0)
                {
                    if (Lside(s) == Rside(s))
                    {
                        WriteLine(s.Length);
                        break;
                    }
                }
            }
        }
        static string Lside(string s)
        {
            string reS = ""; 
            for (int i = 0; i < s.Length / 2; i++)
            {
                reS += s[i].ToString();
            }
            return reS;
        }

        static string Rside(string s)
        {
            string reS = "";
            for (int i = s.Length /2; i < s.Length; i++)
            {
                reS += s[i].ToString();
            }
            return reS;
        }
    }
}