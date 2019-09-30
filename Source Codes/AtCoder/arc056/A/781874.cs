using System;
using System.Linq;

public class Program
{
	public static void Main()
	{
		long[] nums = Console.ReadLine().Split().Select(value => long.Parse(value)).ToArray();
		long price_single = nums[0];
		long price_set = nums[1];
		long orange = nums[2];
		long num_set = nums[3];
		long cost_ceil = (long)Math.Ceiling((double)orange / num_set) * price_set;
		long cost_floor = orange / num_set * price_set + (orange % num_set) * price_single;
		Console.WriteLine(Math.Min(cost_ceil, cost_floor));
	}
}