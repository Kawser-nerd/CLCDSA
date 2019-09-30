using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
       int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
       int W = 0;
       int cnt = 0;
       for(int i = 0 ; i < nums[0] ; i++)
       {
           W += int.Parse(Console.ReadLine());
           if(nums[1] <= W && W <= nums[2]) cnt++;
       }
       Console.WriteLine(cnt);
    }
}