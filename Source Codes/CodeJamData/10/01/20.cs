using System;

class A {
	static void Main() {
		string[] numbers = Console.ReadLine().Split(' ');
		int N = int.Parse(numbers[0]);
		for(int cs=0;cs<N;cs++) {
			string[] nums = Console.ReadLine().Split(' ');
			int n = int.Parse(nums[0]), k = int.Parse(nums[1]);
			if ((k+1)%(1<<n)==0) Console.WriteLine("Case #{0}: ON",cs+1);
			else Console.WriteLine("Case #{0}: OFF",cs+1);
		}
	}
}
