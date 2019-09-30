using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
namespace Solution
{
    class Solution
    {
        static void Main(string[] args)
        {
            string s = System.Console.ReadLine();
            int n = 0;
            int ans = 0;
            for(int i = s.Length-1; i >=0;i--)
            {
                if (s[i] == 'T') n++;
                else if (n > 0) { n--; ans += 2; }
            }
            System.Console.WriteLine(s.Length-ans);
        }

    }
}