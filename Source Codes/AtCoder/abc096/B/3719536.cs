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
            double[] n = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
            Array.Sort(n);
            int K = int.Parse(Console.ReadLine());
            for(int i = 0 ; i < K ; i++)
            {
                n[n.Count()-1] *= 2;
            }
            Console.WriteLine(n[0]+n[1]+n[2]);
        }
    }
}