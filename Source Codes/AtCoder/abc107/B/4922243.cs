using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC107_B();
        }

        static void ABC107_B()
        {
            var HW = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var masu = new string[HW[0] + 1, HW[1] + 1];
            for (var h = 1; h <= HW[0]; h++)
            {
                var a = Console.ReadLine();
                for (var w = 1; w <= HW[1]; w++)
                    masu[h, w] = a[w - 1].ToString();
            }

            for (var h = 1; h <= HW[0]; h++)
            {
                var whiteOnly = true;
                for (var w = 1; w <= HW[1]; w++)
                {
                    if (masu[h, w] == "#")
                        whiteOnly = false;
                }

                if (whiteOnly)
                {
                    for (var w = 1; w <= HW[1]; w++)
                        masu[h, w] = "";
                }
            }

            for (var w = 1; w <= HW[1]; w++)
            {
                var whiteOnly = true;
                for (var h = 1; h <= HW[0]; h++)
                {
                    if (masu[h, w] == "#")
                        whiteOnly = false;
                }

                if (whiteOnly)
                {
                    for (var h = 1; h <= HW[0]; h++)
                        masu[h, w] = "";
                }
            }

            for (var h = 1; h <= HW[0]; h++)
            {
                for (var w = 1; w <= HW[1]; w++)
                {
                    if (masu[h, w] != "")
                        Console.Write(masu[h, w]);
                }

                var count = 0;
                for (var w = 1; w <= HW[1]; w++)
                {
                    if (masu[h, w] == "")
                        count++;
                }
                if (count != HW[1])
                    Console.WriteLine("");
            }
        }
    }
}