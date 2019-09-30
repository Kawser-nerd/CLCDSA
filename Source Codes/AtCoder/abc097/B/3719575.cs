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
            double X= double.Parse(Console.ReadLine());
            
            double max = 1;
            double ans = 0;
            
            for(int i = 1; i < Math.Sqrt(X) ; i++)
            {
                for(int j = 2; j < Math.Sqrt(X); j++)
                {
                    ans = Math.Pow(i,j);
                    if(ans <= X)
                    {
                        max = Math.Max(ans,max);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            Console.WriteLine(max);
            
        }
    }
}