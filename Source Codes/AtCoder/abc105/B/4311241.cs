using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var N = int.Parse(ReadLine());

            for (int i = 0; i * 4 <= N; i++)
            {
                var num = N;
                num = num - i * 4;
                if (num < 0) continue;
                for (int j = 0; num >= j * 7; j++)
                {
                    if (num - j * 7 == 0)
                    {
                        WriteLine("Yes");
                        return;
                    }
                }
            }
            WriteLine("No");
        }
    }
}