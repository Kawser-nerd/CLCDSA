using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
using static System.Math;

class Program{
	static int n;
	static int X;
	static int[] x;

	static void Main(){
		string[] input = Console.ReadLine().Split();
		n = int.Parse(input[0]);
		X = int.Parse(input[1]);
		x = Console.ReadLine().Split().Select(int.Parse).ToArray();

		if (n == 1){
			Console.WriteLine(Abs(X - x[0]));
			return;
		}

		int min = Min(x.Min(),X);
		List<int> dis = new List<int>();
		foreach (var xi in x) if (xi != min) dis.Add(xi - min);
		if (X != min) dis.Add(X - min);

		Console.WriteLine(GCD(dis.ToArray()));
	}

	public static int GCD(int a, int b) //????????
    {
        return a > b ? GcdRecursive(a, b) : GcdRecursive(b, a);
    }

    private static int GcdRecursive(int a, int b)
    {
        return b == 0 ? a : GcdRecursive(b, a % b);
    }

    public static int GCD(params int[] nums) //????????
    {
        int n = nums.Length;
        int ans = GCD(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            ans = GCD(ans, nums[i]);
        return ans;
    }
}