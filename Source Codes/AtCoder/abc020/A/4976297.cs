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
            string input = Console.ReadLine();

            switch(input)
            {
                case "1":
                    Console.WriteLine("ABC");
                    break;
                case "2":
                    Console.WriteLine("chokudai");
                    break;
                dafult:
                    break;
            }
        }
    }
}