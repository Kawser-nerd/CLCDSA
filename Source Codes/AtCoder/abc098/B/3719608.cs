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
            string s = Console.ReadLine();
            
            int max = 0;
            string s1 = "";
            string s2 = "";
            
            int cnt = 0;
            for(int i = 1 ; i < s.Length ; i++)
            {
                s1 = s.Substring(0,i);
                s2 = s.Substring(i,n-i);
                cnt = 0;
                
                for(int j = 0 ; j < 26 ; j++)
                {
                    char c = (char)('a'+j);
                    if(s1.Contains(c) && s2.Contains(c)) cnt++;
                }
                max = Math.Max(max,cnt);
            }
            Console.WriteLine(max);
        }
    }
}