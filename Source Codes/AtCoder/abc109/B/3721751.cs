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
            bool ok = true;
            
            List<string> list = new List<string>();
            string s1 = Console.ReadLine();
            list.Add(s1);
            string s2 = "";
            for(int i = 1; i < n ; i++)
            {
                s2 = Console.ReadLine();
                if(s1[s1.Length-1] != s2[0]) ok = false;
                if(list.Contains(s2)) ok = false;
                list.Add(s2);
                s1 = s2;
            }
            
            if(ok) Console.WriteLine("Yes");
            else Console.WriteLine("No");
        }
    }
}