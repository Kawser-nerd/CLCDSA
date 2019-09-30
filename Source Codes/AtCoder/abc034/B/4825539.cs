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
            int n = int.Parse(ReadLine());
            if (n%2 ==1)
            {
                WriteLine(n + 1);
            }
            else
            {
                WriteLine(n - 1);
            }
        }
    }
}