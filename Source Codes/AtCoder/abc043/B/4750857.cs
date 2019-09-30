using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            string ans = "";
            for (int i = 0; i < s.Length; i++)
            {
                switch(s[i]){
                    case '0':
                        ans += "0";
                        break;
                    case '1':
                         ans += "1";
                         break;
                    case 'B':
                        if (ans.Length>0)
                        {
                            ans = ans.Remove(ans.Length-1);
                        }
                        break;
                }
            }
            WriteLine(ans);
        }
    }
}