using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoderABC115
{
    class Program
    {
        public static void Main(string[] args)
        {
            int D = int.Parse(Console.ReadLine());
            Console.WriteLine(
                (D == 25)? "Christmas":
                (D == 24)? "Christmas Eve":
                (D == 23)? "Christmas Eve Eve":
                "Christmas Eve Eve Eve"
            );
        }
    }
}