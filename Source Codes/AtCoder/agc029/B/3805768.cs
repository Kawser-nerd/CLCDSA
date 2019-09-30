using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
		Array.Sort(nums);
		long answer = 0;
		int first = 0;
		int second = n-1;
		long aimNum = 1073741824;
		bool[] used = new bool[n];
		for(int i = 0; i < n; i++) used[i] = false;
		
		while(true)
		{
			if(n == 1 || aimNum == 1) break;
			first = 0;
			second = n-1;
			while(true)
			{
				if(nums[first] + nums[second] == aimNum)
				{
					if((!used[first]) && (!used[second]))
					{
						answer++;
						used[first] = true;
						used[second] = true;
						first++;
						second--;
					}else if(!used[first])
					{
						second--;
					}else if(!used[second])
					{
						first++;
					}else
					{
						first++;
						second--;
					}
				}else
				{
					if(nums[first] + nums[second-1] < aimNum) first++;
					else second--;
				}
				
				if(first >= second) break;

			}
			aimNum /= 2;
		}
		
		Console.WriteLine(answer);
	}

}