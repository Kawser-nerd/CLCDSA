using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Console.ReadLine().Select(c => c - '0').Where(c => c >= 0 && c <= 9).Aggregate((p, q) => p * 10 + q));
        }
    }
}