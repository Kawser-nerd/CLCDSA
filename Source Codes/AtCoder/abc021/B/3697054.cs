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
    	    List<int> list2 = new List<int>();
            int n = int.Parse(Console.ReadLine());
            int[] nums = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
            int k = int.Parse(Console.ReadLine());
    	    
    	    for(int i = 0 ; i < nums.Length; i++)
    	    {
    	        list.Add(nums[i]);
    	    }
    	    
    	    nums = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
    	    for(int i = 0 ; i < nums.Length; i++)
    	    {
    	        list.Add(nums[i]);
    	    }
    	    
    	    for(int i = 0 ; i < list.Count ; i++)
    	    {
    	        if(!list2.Contains(list[i]))
    	        {
    	            list2.Add(list[i]);
    	        }
    	    }
    	    
    	    if(list.Count != list2.Count)
    	    {
    	        Console.WriteLine("NO");
    	    }
    	    else
    	    {
    	        Console.WriteLine("YES");
    	    }
    	}
    }
}