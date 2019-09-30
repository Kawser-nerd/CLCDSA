using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');

            //??????????????? 3 
            var a = int.Parse(input[0]);

            //?????????????? 1
            var b = int.Parse(input[1]);

            //???????????? 4
            var c = int.Parse(input[2]);

            var gedokuyaku = a + b;
            //4

            var doku = 0;

            if (c < gedokuyaku + 1)
            {
                doku = c;
            }
            else
            {
                doku = gedokuyaku + 1;
            }

            var oisii = b;



            Console.WriteLine(doku +oisii);
        }    
    }
}