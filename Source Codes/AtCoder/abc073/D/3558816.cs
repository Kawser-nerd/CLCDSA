using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static string[] input = Console.ReadLine().Split(' ');
static long n = long.Parse(input[0]);
static long m = long.Parse(input[1]);
static int r = int.Parse(input[2]);
static long[,] moveMatrix = new long[n,n];
static long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
static List<int> numListOri = Enumerable.Range(0,r).ToList();//0,1,...,n-1?n????????
static List<int> numListEnd = new List<int>(); //??????????????????????????
static long answer = long.MaxValue;

	static void Main()
	{
    for(int i = 0; i < r; i++) nums[i]--;

    for(int i = 0; i < n; i++)
    {
      for(int j = i+1; j < n; j++)
      {
        moveMatrix[i,j] = 9999999999999;
        moveMatrix[j,i] = 9999999999999;
      }
    }
    
    for(long i = 0; i < m; i++)
    {
      long[] numsSub = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      moveMatrix[numsSub[0]-1,numsSub[1]-1] = numsSub[2];
      moveMatrix[numsSub[1]-1,numsSub[0]-1] = numsSub[2];
    }

    for(int k = 0; k < n; k++)
    {
      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < n; j++)
        {
          if(moveMatrix[i,j] > moveMatrix[i,k] + moveMatrix[k,j])
            moveMatrix[i,j] = moveMatrix[i,k] + moveMatrix[k,j];//?????
        }
      }
    }

    Permutation(numListOri, numListEnd);//???????
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}

  static void Permutation(List<int> numListOri, List<int> numListEnd)//???????
    {
      for(int i = 0; i < numListOri.Count(); i++)//numListOri?????????????
      {
        int x = numListOri[i];//??????
        numListEnd.Add(x);
        numListOri.RemoveAt(i);
        
        if(numListOri.Count() > 0) Permutation(numListOri, numListEnd);//?????
        else
        {
          long memo = 0;
          for(int j = 0; j < numListEnd.Count()-1; j++)
          {
            memo += moveMatrix[nums[numListEnd[j]], nums[numListEnd[j+1]]];
          }
          //Console.WriteLine(memo+" "+nums[numListEnd[0]]+nums[numListEnd[1]]);
          answer = Math.Min(memo, answer);
        }
        
        numListOri.Insert(i, x);//listOriginal???
        numListEnd.RemoveAt(numListEnd.Count()-1);
      }
    }

}