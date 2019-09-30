using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());//long.Parse???????????
	long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
  long[,] numZeros = new long[n,21];//0????????
  long[] zeroMemo = new long[21];
  long answer = 0;

    for(long i = 0; i < n; i++)//??????
    {
      long[] zeroMem = BinaryArray(nums[i]);
      for(long j = 0; j < 21; j++)
      {
        numZeros[i,j] = zeroMem[j];
      }
    }

    long look = 0;
    long checkNum = 0;
    for(long i = 0; i < n; i++)
    {
      bool isProblem = false;
      for(long j = 0; j < 21; j++)
      {
        if(numZeros[i,j] == 1) zeroMemo[j]++;
        if(zeroMemo[j] == 2) isProblem = true;
      }
      //Console.WriteLine(" "+zeroMemo[3]+zeroMemo[2]+zeroMemo[1]+zeroMemo[0]);
      if(isProblem)
      {
      while(true)
        {
          look--;
          bool isProblemSub = false;
          for(long j = 0; j < 21; j++)
          {
            if(numZeros[checkNum,j] == 1) zeroMemo[j]--;
            if(zeroMemo[j] == 2) isProblemSub = true;
          }
          checkNum++;
          //Console.WriteLine(" "+zeroMemo[3]+zeroMemo[2]+zeroMemo[1]+zeroMemo[0]+"m");
          if(!(isProblemSub)) break;
        }
      }
      answer += look + 1;
      //Console.WriteLine(answer);
      look++;
    }
  
	Console.WriteLine(answer);
	}

  static long[] BinaryArray(long n)//??n??[0]???????????????
  {
    long returnNum = 21;//????
    long[] nums = new long[returnNum];
    long memo = 2;
    for(long i = 0; i < returnNum; i++)
    {
      if(n % memo == memo / 2)
      {
        nums[i] = 1;
        n -= memo / 2;
      }
    memo *= 2;
    }
    //Console.WriteLine(" "+nums[3]+nums[2]+nums[1]+nums[0]);
    return nums;
  }
/*
  static long[] ArrayAdd(long[] a, long[] b)//?????????????????????
  {
  long[] c = new long[a.Length];
    for(long i = 0; i < a.Length; i++)
    {
      c[i] = a[i] + b[i];
    }
  return c;
  }

  static long[] ArraySubtract(long[] a, long[] b)//???????????????(a-b)??????
  {
  long[] c = new long[a.Length];
    for(long i = 0; i < a.Length; i++)
    {
      c[i] = a[i] - b[i];
    }
  return c;
  }
*/

}