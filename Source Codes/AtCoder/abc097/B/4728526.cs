using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static int x;
        
        static void Main(string[] args)
        {
            //[summary]B - Exponential
            x = int.Parse(Console.ReadLine());
            
            int sqrt = (int)Math.Sqrt(x);
            var pows = new List<int>() { 1 };
            
            for(int i = 2; i <= sqrt; i++)
            {
                int pow = GetMaxPower(i);
                pows.Add(pow);
            }
            
            Console.WriteLine(pows.Max());
        }
        
        static int GetMaxPower(int n)
        {
            int i = 2;
            int pow = (int)Math.Pow(n, i);
            
            while(pow <= x)
            {
                i++;
                pow = (int)Math.Pow(n, i);
            }
            
            if(pow <= x)
            {
                return pow;    
            }
            else
            {
                return (int)Math.Pow(n, i - 1);
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