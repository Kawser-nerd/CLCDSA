using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	

    public static int ans = 0;
    public static int n;

  
    public static void Main()
	{
        n = int.Parse(Console.ReadLine());
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        
        int f = 0;
        for(int i = 0 ; i < n ; i++){
            f += nums[i]-1;
        }
        Console.WriteLine(f);
 
        
    }
}