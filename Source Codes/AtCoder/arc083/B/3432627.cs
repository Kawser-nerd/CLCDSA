using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
    long[,] moveMatrix = new long[n,n];
    bool[,] smallerPath = new bool[n,n];//?????
    bool answer = true;
    bool countPlus = true;
    long answerCount = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      for(long j = 0; j < n; j++) moveMatrix[i,j] = nums[j];
    }

    for(int k = 0; k < n; k++)
    {
      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < n; j++)
        {
          if(moveMatrix[i,j] > moveMatrix[i,k] + moveMatrix[k,j])//?????
          {
            answer = false;
          }else if(moveMatrix[i,j] == moveMatrix[i,k] + moveMatrix[k,j]
            && i != k && j!= k)
          {
            smallerPath[i,j] = true;
            smallerPath[j,i] = true;
          }
        }
      }
    }

    for(long i = 0; i < n; i++)
    {
      for(long j = i+1; j < n; j++)
      {
        if(!(smallerPath[i,j])) answerCount += moveMatrix[i,j];
      }
    }
    
		Console.WriteLine((answer) ? answerCount.ToString() : "-1");
	}
}