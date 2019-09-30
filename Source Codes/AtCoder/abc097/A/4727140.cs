using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]Colorful Transceivers
            var line = ReadLine();
            int a =line[0];
            int b = line[1];
            int c = line[2];
            int d = line[3];
            
            if(Math.Abs(a - c) <=d | (Math.Abs(a - b) <= d && Math.Abs(b - c) <= d))
            {
                Console.WriteLine("Yes");    
            }else
            {
                Console.WriteLine("No");    
            }
        }
        
        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            return array.Select(x => int.Parse(x)).ToList();
        }
    }
}