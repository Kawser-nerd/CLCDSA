using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC111_A();
        }

        static void ABC111_A()
        {
            var N = Console.ReadLine();
            var l = new List<string>();
            for (var i = 0; i < N.Length; i++)
            {
                if (N[i] == '1')
                    l.Add("9");
                else if (N[i] == '9')
                    l.Add("1");
                else
                    l.Add(N[i].ToString());
            }
            Console.WriteLine(string.Join("", l));
        }
    }
}