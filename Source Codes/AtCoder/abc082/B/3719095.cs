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
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();
            
            List<char> list1 = new List<char>();
            for(int i = 0 ; i < s1.Length ; i++) list1.Add(s1[i]);
            list1.Sort();
            
            List<char> list2 = new List<char>();
            for(int i = 0 ; i < s2.Length ; i++) list2.Add(s2[i]);
            list2.Sort();
            list2.Reverse();
            
            
        
            List<string> sss = new List<string>();
            sss.Add(string.Join("",list1));
            sss.Add(string.Join("",list2));
            sss.Sort();
            
            bool can = false;
            string ss = string.Join("",list1);
            
            
            if(sss[0] == ss) can = true;
            if(can && sss[0] != sss[1])
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}