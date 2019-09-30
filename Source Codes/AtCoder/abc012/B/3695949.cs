using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int time = int.Parse(Console.ReadLine());
    	    
    	    int h = time / 3600;
    	    time = time % 3600;
    	    int m = time / 60;
    	    time = time % 60;
    	    int s = time;
    	    
    	    string hh = h.ToString("D2");
    	    string mm = m.ToString("D2");
    	    string ss = s.ToString("D2");
    	    Console.WriteLine("{0}:{1}:{2}",hh,mm,ss);
    	    
    	}
    }
}