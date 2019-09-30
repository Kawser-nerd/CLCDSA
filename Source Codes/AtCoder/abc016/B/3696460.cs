using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            int[] n = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
            bool a = false;
            bool b = false;
            if(n[0] + n[1] == n[2]) a = true;
            if(n[0] - n[1] == n[2]) b = true;
            
            if(a && b)
            {
                Console.WriteLine("?");
            }
            else if(a)
            {
                Console.WriteLine("+");
            }
     	    else if(b)
     	    {
     	        Console.WriteLine("-");
     	    }
     	    else
     	    {
     	        Console.WriteLine("!");
     	    }
    	}
    }
}