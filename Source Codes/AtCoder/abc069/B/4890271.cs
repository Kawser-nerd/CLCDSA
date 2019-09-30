using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] imp = Console.ReadLine().ToArray();
            int L = imp.Length;
            Console.Write(imp[0]);
            Console.Write(L - 2);
            Console.Write(imp[L - 1]);
        }
    }
}