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
    	    string head = s[0].ToString().ToUpper();
    	    s = s.ToLower();
    	    string ans = "";
    	    ans += head;
    	    for(int i = 1 ; i < s.Length ; i++)
    	    {
    	        ans += s[i];
    	    }
    	    Console.WriteLine(ans);
    	}
    }
}