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
            string name = Console.ReadLine();
            string name1 = name.Substring(0, 1);
            string name2 = name.Substring(1);

            string ans = name1.ToUpper() + name2.ToLower();
            Console.WriteLine(ans);
        }
    }
}