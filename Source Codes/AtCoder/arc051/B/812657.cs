using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var k = Int32.Parse(Console.ReadLine());

            ulong prev = 1;
            ulong cur = 1;
            for (int i = 0; i < k; i++)
            {
                var wk = cur;
                cur = prev + cur;
                prev = wk;
            }

            Console.WriteLine(string.Format("{0} {1}", cur, prev));
        }
    }
}