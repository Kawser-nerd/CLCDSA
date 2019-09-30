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
            int max = 0; int min = int.MaxValue;
            for (int i = 1; i <= 4; i++)
            {
                int tmp = 0;
                for (int j = 0; j < N; j++)
                {
                    if (s[j].ToString() == i.ToString())
                    {
                        tmp++;
                    }
                }
                if (max < tmp)
                {
                    max = tmp;
                }
                if (min > tmp)
                {
                    min = tmp;
                }
            }
            WriteLine(max + " " + min);
        }
    }
}