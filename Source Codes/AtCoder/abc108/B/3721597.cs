using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        public static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int x1 = n[0];
            int y1 = n[1];
            int x2 = n[2];
            int y2 = n[3];
            
            int xc = x2 - x1;
            int yc = y2 - y1;

            Console.WriteLine("{0} {1} {2} {3}", x2 - yc , y2 + xc , x1 - yc , y1 + xc );
        }
    }
}