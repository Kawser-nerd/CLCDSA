using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC122A
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            if (s == "A")
            {
                Console.WriteLine("T");
            }
            if (s == "C")
            {
                Console.WriteLine("G");
            }
            if (s=="G")
            {
                Console.WriteLine("C");
            }
            if (s=="T")
            {
                Console.WriteLine("A");
            }
        }
    }
}