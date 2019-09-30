using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - ?????????
            var line = Console.ReadLine();
            string s = "";

            foreach(var c in line)
            {
                switch (c)
                {
                    case '1':
                        s += '9';
                        break;
                    case '9':
                        s += '1';
                        break;
                    default:
                        s += c;
                        break;
                }
            }

            Console.WriteLine(s);
        }
    }
}