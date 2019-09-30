using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static long[,] combs = new long[51,51];//C(a,b)?0-50??

	static void Main()
	{
    CombsGet();
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		int n = int.Parse(input[0]);
		int a = int.Parse(input[1]);
    int b = int.Parse(input[2]);
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    float maxAverage = 0;
    long answer = 0;
    Array.Sort(nums);
    Array.Reverse(nums);//???
    
    for(int i = 0; i < a; i++) maxAverage += nums[i];  
    maxAverage /= a;
    Console.WriteLine(maxAverage);

    
    if(nums[0] != nums[a-1])
    {
      long x = 1;
      for(int i = a-1; i > 0; i--)
      {
        if(nums[i] == nums[i-1]) x++;
        else break;
      }
      long y = x;
      for(int i = a-1; i < n-1; i++)
      {
        if(nums[i] == nums[i+1]) y++;
        else break;
      }
      Console.WriteLine(combs[y,x]);
    }else
    {
      long y = a;
      for(int i = a-1; i < n-1; i++)
      {
        if(nums[i] == nums[i+1]) y++;
        else break;
      }
      for(int i = a; i <= y && i <= b; i++)
      {
        answer += combs[y,i];
      }
      Console.WriteLine(answer);
    }
	}

  static void CombsGet()//50??????????????
  {
    for(int i = 0; i <= 50; i++)
    {
      combs[i,0] = 1;
      for(int j = 1; j <= i; j++)
      {
        combs[i,j] = combs[i-1,j-1] + combs[i-1,j];
      }
    }
  }
  
}