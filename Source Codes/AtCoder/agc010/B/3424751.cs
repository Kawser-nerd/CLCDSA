using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long sumNums = 0;
    long sumCount = 0;
    long divideCount = 0;
    long[] diffrences = new long[n];
    long divideCheck = 0;
    bool answer = true;

    for(long i = 0; i < n; i++)
    {
      sumCount += i+1;
      sumNums += nums[i];
      if(i != n-1) diffrences[i] = nums[i+1] - nums[i];
    }
    diffrences[n-1] = nums[0] - nums[n-1];
    
    if(sumNums % sumCount != 0) answer = false;
    else
    {
      divideCount = sumNums / sumCount;
      for(long i = 0; i < n; i++)
      {
        diffrences[i] -= divideCount;
        diffrences[i] *= -1;
        if(diffrences[i] % n != 0 || diffrences[i] < 0)
        {
          answer = false;
          break;
        }
        divideCheck += diffrences[i]/n;
      }

      if(divideCheck != divideCount) answer = false;
    }

    Console.WriteLine((answer) ? "YES" : "NO");
    
	}
}