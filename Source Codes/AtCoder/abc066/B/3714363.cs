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
            string s1 = "";
            string s2 = "";
            
            List<char> c = new List<char>();
            for(int i = 0 ; i < s.Length ; i++) c.Add(s[i]);
            
            int ans = 1;
            
            while(c.Count > 0)
            {
                c.RemoveAt(c.Count-1);
                if(c.Count % 2 == 1) c.RemoveAt(c.Count-1);
                
                s1 = "";
                s2 = "";
                int index = c.Count / 2;
                
                for(int i = 0 ; i < index ; i++)
                {
                    s1 += c[i];
                    s2 += c[i+index];
                }
                if(s1 == s2)
                {
                    ans = c.Count;
                    break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}