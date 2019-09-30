using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = n[0];
            int L = n[1];
            
            List<string> list = new List<string>();
            
            for(int i = 0 ; i < N ; i++)
            {
                list.Add(Console.ReadLine());
            }
            list.Sort();
            foreach(string s in list) Console.Write(s);
            Console.WriteLine();
    	}
    }
}