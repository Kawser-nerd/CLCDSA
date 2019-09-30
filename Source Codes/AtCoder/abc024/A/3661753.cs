using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
       int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
       int[] people = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
       int ans = (nums[0] * people[0]) + (nums[1] * people[1]);
       
       if((people[0] + people[1]) >= nums[3]) ans = ans - ((people[0]+people[1]) * nums[2]);
       Console.WriteLine(ans);
    }
}