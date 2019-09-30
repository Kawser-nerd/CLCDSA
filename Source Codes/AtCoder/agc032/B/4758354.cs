using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            label:
            int n = Parse(ReadLine());
            var list = new List<string>();
            if (n % 2 == 0)
            {
                for (int i = 1; i < n; ++i)
                {
                    for (int j = i + 1; j <= n; ++j)
                    {
                        if (i + j != n + 1)
                        {
                            list.Add($"{i} {j}");
                        }
                    }
                }
            }
            else
            {
                for (int i = 1; i < n; ++i)
                {
                    for (int j = i + 1; j <= n; ++j)
                    {
                        if (i + j != n)
                        {
                            list.Add($"{i} {j}");
                        }
                    }
                }
            }
            WriteLine(list.Count);
            foreach (var s in list) WriteLine(s);
            //goto label;
        }
    }
}