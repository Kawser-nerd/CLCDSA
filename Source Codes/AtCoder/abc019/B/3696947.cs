using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            char[] c = Console.ReadLine().ToCharArray();
            string s = "";
            
            List <string> list = new List<string>();
            
            for(int i = 0 ; i < c.Length ; i++)
            {
                s += c[i];
                if(i == c.Length-1)
                {
                    list.Add(s);
                }
                else if(i < c.Length-1) 
                {
                    if(c[i] != c[i+1])
                    {
                        list.Add(s);
                        s = "";
                    }
                }
               
            }
            for(int i = 0 ; i < list.Count ; i++)
            {
                string ss = list[i];
                Console.Write(ss[0]+""+ss.Length);
            }
            Console.WriteLine();
    	}
    }
}