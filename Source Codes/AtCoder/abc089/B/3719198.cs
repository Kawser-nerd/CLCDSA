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
           string[] input = Console.ReadLine().Split(' ');
           
           bool four = false;
           for(int i = 0 ; i < n ; i++)
           {
               if(input[i] == "Y") four = true;
           }
           
           if(four) Console.WriteLine("Four");
           else Console.WriteLine("Three");
        }
    }
}