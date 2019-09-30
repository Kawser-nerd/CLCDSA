using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long m = long.Parse(input[1]);
    long[,] vertexes = new long[n,3];//???????
    long[] sumPPP = new long[n];
    long[] sumPPm = new long[n];
    long[] sumPmP = new long[n];
    long[] sumPmm = new long[n];
    long[] summPP = new long[n];
    long[] summPm = new long[n];
    long[] summmP = new long[n];
    long[] summmm = new long[n];
    long answer = 0;
    long memo = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      sumPPP[i] = nums[0] + nums[1] + nums[2];
      sumPPm[i] = nums[0] + nums[1] - nums[2];
      sumPmP[i] = nums[0] - nums[1] + nums[2];
      sumPmm[i] = nums[0] - nums[1] - nums[2];
      summPP[i] = -nums[0] + nums[1] + nums[2];
      summPm[i] = -nums[0] + nums[1] - nums[2];
      summmP[i] = -nums[0] - nums[1] + nums[2];
      summmm[i] = -nums[0] - nums[1] - nums[2];
    }
    Array.Sort(sumPPP);
    Array.Sort(sumPPm);
    Array.Sort(sumPmP);
    Array.Sort(sumPmm);
    Array.Sort(summPP);
    Array.Sort(summPm);
    Array.Sort(summmP);
    Array.Sort(summmm);
    Array.Reverse(sumPPP);
    Array.Reverse(sumPPm);
    Array.Reverse(sumPmP);
    Array.Reverse(sumPmm);
    Array.Reverse(summPP);
    Array.Reverse(summPm);
    Array.Reverse(summmP);
    Array.Reverse(summmm);

    memo = 0;
    for(int i = 0; i < m; i++) memo += sumPPP[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += sumPPm[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += sumPmP[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += sumPmm[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += summPP[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += summPm[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += summmP[i];
    answer = Math.Max(answer, Math.Abs(memo));
    memo = 0;
    for(int i = 0; i < m; i++) memo += summmm[i];
    answer = Math.Max(answer, Math.Abs(memo));
    
		Console.WriteLine(answer);
	}
}