using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Math;

namespace Atcoder
{

    class AtCodeeeeeeeeeeeeeeeeeeeer
    {
        static void Main(string[] args)
        {
            int a = int.Parse(ReadLine());
            int b = int.Parse(ReadLine());
            int n = int.Parse(ReadLine());
            for (int i = n; i < 1000000; i++)
            {
                if (i % a==0&&i % b ==0)
                {
                    WriteLine(i);
                    break;
                }
            }
        }
    }

}