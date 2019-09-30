using System;
using System.Collections.Generic;
using System.Linq;

namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');

            double  e = double.Parse(str[0]); 
            double  x = double.Parse(str[1]); 
            double  a = double.Parse(str[2]);
            double  b = double.Parse(str[3]);
            double  c = double.Parse(str[4]);
            double  d = double.Parse(str[5]);

            double aiuo = ((((a-e)*(d-x))-((b-x)*(c-e)))/2);
            Console.WriteLine(Math.Abs(aiuo));
        }
    }
}