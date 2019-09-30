using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class ABC
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int a = int.Parse(S[0].ToString());
            int b = int.Parse(S[1].ToString());
            int c = int.Parse(S[2].ToString());
            int d = int.Parse(S[3].ToString());

            if (a + b + c + d == 7) Console.WriteLine(a + "+" + b + "+" + c + "+" + d + "=7");
            else if (a - b + c + d == 7) Console.WriteLine(a + "-" + b + "+" + c + "+" + d + "=7");
            else if (a + b - c + d == 7) Console.WriteLine(a + "+" + b + "-" + c + "+" + d + "=7");
            else if (a + b + c - d == 7) Console.WriteLine(a + "+" + b + "+" + c + "-" + d + "=7");
            else if (a - b - c + d == 7) Console.WriteLine(a + "-" + b + "-" + c + "+" + d + "=7");
            else if (a - b + c - d == 7) Console.WriteLine(a + "-" + b + "+" + c + "-" + d + "=7");
            else if (a + b - c - d == 7) Console.WriteLine(a + "+" + b + "-" + c + "-" + d + "=7");
            else if (a - b - c - d == 7) Console.WriteLine(a + "-" + b + "-" + c + "-" + d + "=7");

                                                         
            Console.ReadLine();
        }
    }
}