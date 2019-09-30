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
            List<char> list = new List<char>();
            
            for(int i = 0 ; i < s.Length ; i++)
            {
                if(s[i]=='B')
                {
                    if(list.Count > 0)list.RemoveAt(list.Count-1);
                }
                else
                {
                    list.Add(s[i]);
                }
            }
            string ss = String.Join("",list);
            Console.WriteLine(ss);
    	}
    }
}