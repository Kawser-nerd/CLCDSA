using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            char turn = 'A';
            List<char> sa = new List<char>();
            List<char> sb = new List<char>();
            List<char> sc = new List<char>();
            
            string s = Console.ReadLine();
            for(int i = 0 ; i < s.Length ; i++) sa.Add(s[i]);
            s = Console.ReadLine();
            for(int i = 0 ; i < s.Length ; i++) sb.Add(s[i]);
            s = Console.ReadLine();
            for(int i = 0 ; i < s.Length ; i++) sc.Add(s[i]);
            
            
            while(true)
            {
                if(turn == 'A')
                {
                    if(sa.Count == 0) break;
                    else
                    {
                        turn = char.ToUpper(sa[0]);
                        sa.RemoveAt(0);
                    }
                }
                else if(turn == 'B')
                {
                    if(sb.Count == 0) break;
                    else
                    {
                        turn = char.ToUpper(sb[0]);
                        sb.RemoveAt(0);
                    }
                }
                else
                {
                    if(sc.Count == 0) break;
                    else
                    {
                        turn = char.ToUpper(sc[0]);
                        sc.RemoveAt(0);
                    }
                }
            }
            Console.WriteLine(turn);
    	}
    }
}