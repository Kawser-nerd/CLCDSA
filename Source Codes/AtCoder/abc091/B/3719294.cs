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
            List<string> name = new List<string>();
            List<int> kazu = new List<int>();
            int max = 0;
            int n = int.Parse(Console.ReadLine());
            
            string s = "";
            for(int i = 0 ; i < n ; i++)
            {
                s = Console.ReadLine();
                if(!name.Contains(s))
                {
                    name.Add(s);
                    kazu.Add(0);
                }
                kazu[name.IndexOf(s)]++;
            }
            
            int m = int.Parse(Console.ReadLine());
            for(int i = 0 ; i < m ; i++)
            {
                s = Console.ReadLine();
                if(name.Contains(s))
                {
                    kazu[name.IndexOf(s)]--;
                }
            }
            
            for(int i = 0 ; i < kazu.Count ; i++)
            {
                max = Math.Max(max, kazu[i]);
            }
            
            Console.WriteLine(max);
        }
    }
}