using System;
using System.Collections.Generic;
using System.Linq;

namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            string a = str.Replace("a","");
            a = a.Replace("i","");
            a = a.Replace("u","");
            a = a.Replace("e","");
            a = a.Replace("o","");
            Console.WriteLine(a);
        }
    }
}