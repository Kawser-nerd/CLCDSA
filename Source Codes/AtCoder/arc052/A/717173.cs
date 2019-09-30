using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication15
{
    class Program
    {
        static void Main(string[] args)
        {
            foreach (char c in Console.ReadLine())
            {
                if (48 <= (int)c && (int)c <= 57)
                    Console.Write(c);
            }
            Console.WriteLine();
        }
    }
}