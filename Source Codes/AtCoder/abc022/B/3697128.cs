using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    List<int> list = new List<int>();
            int cnt = 0;
            int n = int.Parse(Console.ReadLine());

    	    for(int i = 0 ; i < n; i++)
    	    {
    	        list.Add(int.Parse(Console.ReadLine()));
    	    }
            list.Sort();
    	    for(int i = 1 ; i < list.Count ; i++)
    	    {
    	        if(list[i] == list[i-1]) cnt++;
    	    }
    	    
    	    Console.WriteLine(cnt);
    	}
    }
}