using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            bool choku = true;
            string s;
            if((s = Console.ReadLine())!=null){   
                for(int i = 0 ; i < s.Length ; i++)
                {
                    string a = "";
                    a += s[i];
                    if(a == "c" && i < s.Length-1)
                    {
                        a += s[i+1];
                        if(a != "ch") choku = false;
                    }
                    else if ( a == "h" & i > 0)
                    {
                        a += s[i-1];
                        if(a != "hc") choku = false;
                    }
                    else if (a != "o" && a != "k" && a != "u")
                    {
                        choku = false;
                    }
                }
            }
            
        
            if(choku)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
    	}
    }
}