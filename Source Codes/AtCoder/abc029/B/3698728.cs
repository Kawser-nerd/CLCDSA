using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    List<string> list = new List<string>();
    	    
    	    for(int i = 0 ; i < 12 ; i++)
    	    {
    	        list.Add(Console.ReadLine());
    	    }
    	    
    	    int cnt = 0;
    	    for(int i = 0 ; i < list.Count ; i++)
    	    {
    	        if(list[i].Contains("r")) cnt++;
    	    }
    	    Console.WriteLine(cnt);
    	}
    }
}