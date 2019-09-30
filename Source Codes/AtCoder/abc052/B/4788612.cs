using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;

namespace AtCoder
{
    class AtCoderrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            string s = ReadLine();
            int ans = 0;
            int x = 0;
            for (int i = 0; i < N; i++)
            {
                if (s[i] == 'I')
                {
                    x++;
                }
                else
                {
                    x--;
                }
                if (x>ans)
                {
                    ans = x;
                }
            }
            WriteLine(ans);
        }
    }
}