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
    	    string[] target = new string[6] {"A","B","C","D","E","F"};
    	    int[] kaisuu = new int[6];
    	
    	    for(int i = 0 ; i < 6 ; i++)
    	    {
    	        kaisuu[i] = CountChar(s,target[i]);
    	    }
            
            string ans = String.Join(" ", kaisuu);
            Console.WriteLine(ans);
    	}
    	
    	public static int CountChar(string s , string target)
    	{
    	    int a = s.Length - (s.Replace(target,"").Length);
    	    return a;
    	}
    }
}