using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
    long[][] vertexesL = new long[n][];//?????
    long[][] vertexesR = new long[n][];
    long[] looked = new long[n];//L?R???????????1
    long checkingL = 0;
    long checkingR = 0;
    long answer = 0;
    long distanceMemo = 0;//????????
    long nowPosition = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexesL[i] = new long[2];
      vertexesL[i][0] = nums[0];
      vertexesL[i][1] = i;
      vertexesR[i] = new long[2];
      vertexesR[i][0] = nums[1];
      vertexesR[i][1] = i;
    }

    Array.Sort(vertexesL, (a, b) => b[0].CompareTo(a[0]));//???
    Array.Sort(vertexesR, (a, b) => a[0].CompareTo(b[0]));

    while(true)
    {
      while(true)//??
      {
        if(looked[vertexesL[checkingL][1]] == 0)
        {
          if(nowPosition < vertexesL[checkingL][0])//??????
          {
            distanceMemo += Math.Abs(nowPosition - vertexesL[checkingL][0]);
            nowPosition = vertexesL[checkingL][0];
          }
          looked[vertexesL[checkingL][1]] = 1;
          break;
        }else checkingL++;
        if(checkingL >= n) break;
      }
      while(true)//??
      {
        if(looked[vertexesR[checkingR][1]] == 0)
        {
          if(nowPosition > vertexesR[checkingR][0])//??????
          {
            distanceMemo += Math.Abs(nowPosition - vertexesR[checkingR][0]);
            nowPosition = vertexesR[checkingR][0];
          }
          looked[vertexesR[checkingR][1]] = 1;
          break;
        }else checkingR++;
        if(checkingR >= n) break;
      }
      if(checkingR >= n)//??????
      {
        distanceMemo += Math.Abs(nowPosition);
        answer = Math.Max(answer, distanceMemo);
        break;
      }
    }

    nowPosition = 0;
    distanceMemo = 0;
    checkingL = 0;
    checkingR = 0;

    while(true)
    {
      while(true)//??
      {
        if(looked[vertexesR[checkingR][1]] == 1)
        {
          if(nowPosition > vertexesR[checkingR][0])//??????
          {
            distanceMemo += Math.Abs(nowPosition - vertexesR[checkingR][0]);
            nowPosition = vertexesR[checkingR][0];
          }
          looked[vertexesR[checkingR][1]] = 2;
          break;
        }else checkingR++;
      if(checkingR >= n) break;
      }
    
      while(true)//??
      {
        if(looked[vertexesL[checkingL][1]] == 1)
        {
          if(nowPosition < vertexesL[checkingL][0])//??????
          {
            distanceMemo += Math.Abs(nowPosition - vertexesL[checkingL][0]);
            nowPosition = vertexesL[checkingL][0];
          }
          looked[vertexesL[checkingL][1]] = 2;
          break;
        }else checkingL++;
        if(checkingL >= n) break;
      }
      if(checkingL >= n)//??????
      {
        distanceMemo += Math.Abs(nowPosition);
        answer = Math.Max(answer, distanceMemo);
        break;
      }
    }
    
		Console.WriteLine(answer);
	}
}