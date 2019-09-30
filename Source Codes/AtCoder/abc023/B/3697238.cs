using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    List <char> acs = new List<char>();
    	    int n = int.Parse(Console.ReadLine());
    	    string target = Console.ReadLine();
    	    
    	    acs.Add('b');
    	    int a = 0;

    	    while(acs.Count < n)
    	    {
    	        if((a+1)%3 == 1)
    	        {
    	            acs.Insert(0,'a');
    	            acs.Add('c');
    	        }
    	        else if ((a+1)%3 == 2)
    	        {
    	            acs.Insert(0,'c');
    	            acs.Add('a');
    	        }
    	        else
    	        {
    	            acs.Insert(0,'b');
    	            acs.Add('b');
    	        }
    	        a++;
    	        
    	    }
    	    string ss = "";
    	    foreach(char c in acs) ss += c;

    	    if(ss == target)
    	    {
    	        Console.WriteLine(a);
    	    }
    	    else
    	    {
    	        Console.WriteLine(-1);
    	    }
    	}
    }
}