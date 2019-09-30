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
            string s = Console.ReadLine();
            
            string s2 = "";
            bool yes = true;
            
            for(int i = 0 ; i < s.Length ; i++)
            {
                s2 = s[i].ToString();

                if(Count(s,s2) > 1) yes = false;
            }
            if(yes) Console.WriteLine("yes");
            else Console.WriteLine("no");
        }
        
        public static int Count(string s,string s2)
        {
            int cnt = 0 ;
            cnt = s.Length - s.Replace(s2,"").Length;
            return cnt;
            
        }
    }
}