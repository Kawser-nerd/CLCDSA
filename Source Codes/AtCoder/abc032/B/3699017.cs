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
            int n = int.Parse(Console.ReadLine());
            
            List <string> list = new List<string>();
            
            for(int j = 0 ; j < s.Length-n+1 ; j++)
            {
                string text = s.Substring(j,n);
                if(!list.Contains(text))
                {
                    list.Add(text);
                }
            }
            
            Console.WriteLine(list.Count);

    	}
    }
}