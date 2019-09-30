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
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[9] {0,1,2,4,8,16,32,64,128};
            
            for(int i = a.Length-1; i > 0 ;i--)
            {
                if(a[i] <= n)
                {
                    Console.WriteLine(a[i]);
                    break;
                }
            }
        }
        
    }
}