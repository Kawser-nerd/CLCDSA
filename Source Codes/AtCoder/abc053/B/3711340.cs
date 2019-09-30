using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            string s = Console.ReadLine();
            int a = s.IndexOf('A');
            int b = s.LastIndexOf('Z');
            
            Console.WriteLine(b-a+1);
    	}
    }
}