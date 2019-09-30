using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace ConsoleApp112 {
    class Program {
        static void Main(string[] args)
        {
            string X = Console.ReadLine();
            char[] Y = X.ToCharArray();

            var dict = new Dictionary<char, int>()
            {
                {'A', 1},
                {'B', 2 },
                {'C', 3 },
                {'D', 4 }

            };

            switch (Y[0])
            {
                case 'A':
                    Console.WriteLine(1);
                    break;
                case 'B':
                    Console.WriteLine(2);
                    break;
                case 'C':
                    Console.WriteLine(3);
                    break;
                case 'D':
                    Console.WriteLine(4);
                    break;
                case 'E':
                    Console.WriteLine(5);
                    break;
                default:
                    break;
            }
        }
    }
}