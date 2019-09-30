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
            Console.WriteLine(new string(Console.ReadLine().Where(c => c - '0' >= 0 && c - '0' <= 9).ToArray()));
        }
    }
}