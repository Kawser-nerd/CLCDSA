using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {


            string[] str = Console.ReadLine().Split(' ');

            string strer = str[0] + str[1];

            Console.WriteLine(2 * int.Parse(strer));

        }
    }
}