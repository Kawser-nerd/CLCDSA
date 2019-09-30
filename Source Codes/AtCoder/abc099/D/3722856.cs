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
		long c = long.Parse(input[1]);
    long answer = long.MaxValue;
    long answerMemo = 0;
    long[,] originalColors = new long[c,3];//??????????????
    
    int[,] matrixDistance = new int[c,c];//??
    for(int i = 0; i < c; i++)//??????
    {
    	int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
    	for(int j = 0; j < c; j++) matrixDistance[i,j] = nums[j];//???????
    }

    int[,] matrixColor = new int[n,n];//??  
    for(int i = 0; i < n; i++)//??????
    {
    	int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
    	for(int j = 0; j < n; j++) matrixColor[i,j] = nums[j]-1;//???????
    }

    for(int a = 0; a < n; a++)
    {
      for(int b = 0; b < n; b++)
      {
        if((a+b)% 3 == 0)
          originalColors[matrixColor[a,b],0]++;
        if((a+b)% 3 == 1)
          originalColors[matrixColor[a,b],1]++;
        if((a+b)% 3 == 2)
          originalColors[matrixColor[a,b],2]++;
      }
    }

    for(int i = 0; i < c; i++)//????
    {
      for(int j = 0; j < c; j++)
      {
        for(int k = 0; k < c; k++)
        {
          if(i == j || i == k || j == k) continue;//??????
          answerMemo = 0;
          for(int a = 0; a < c; a++)
          {
            answerMemo += matrixDistance[a,i] * originalColors[a,0];
            answerMemo += matrixDistance[a,j] * originalColors[a,1];
            answerMemo += matrixDistance[a,k] * originalColors[a,2];
          }

          answer = Math.Min(answer, answerMemo);
        }
      }
    }

    
		Console.WriteLine(answer);
	}
}