using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            string[] str = Console.ReadLine().Split(' ');
            string s = str[0]+str[1];
            int n = int.Parse(s);
            Console.WriteLine(n*2);
    	}
    }
}