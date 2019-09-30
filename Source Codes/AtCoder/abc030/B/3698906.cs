using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            double[] n = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
            double h = n[0] % 12 * 60;
            double m = n[1];
            
            h = (h+m) * 0.5;
            m = m * (360 / 60);
            double ans = Math.Min(Math.Abs(h-m),(360-Math.Abs(m-h)));
            Console.WriteLine(ans);
    	}
    }
}