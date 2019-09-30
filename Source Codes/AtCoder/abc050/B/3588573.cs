using System;
using System.Collections;
using System.Linq;


public class Test
{	public static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		string[] str = Console.ReadLine().Split(' ');
		int[] nums = new int[str.Length];
		int ans = 0;

		for(int i = 0 ; i < nums.Length ; i++)
		{
			nums[i] = int.Parse(str[i]);
		}

		int m = int.Parse(Console.ReadLine());
		int P = 0;
		int X = 0;
		for(int i = 0 ; i < m ; i++)
		{
			ans = 0;
			str = Console.ReadLine().Split(' ');
			P = int.Parse(str[0]);
			X = int.Parse(str[1]);
			for(int j = 0 ; j < nums.Length ; j++)
			{
				if(j+1 == P)
				{
					ans += X;
				}
				else {
					ans += nums[j];
				}
			}
			Console.WriteLine(ans);
		}
	}
}