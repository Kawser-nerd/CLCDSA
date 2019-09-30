using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC108_A();
        }

        static void ABC108_A()
        {
            var K = int.Parse(Console.ReadLine());
            var a = 0;
            var b = 0;
            for(var i = 1; i <= K; i+=2)
                    a++;

            for (var i = 2; i <= K; i+=2)
                    b++;

            Console.WriteLine(a * b);
        }
    }
}