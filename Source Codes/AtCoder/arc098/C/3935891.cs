using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');
		int n = int.Parse(input[0]);
		int k = int.Parse(input[1]);
    int q = int.Parse(input[2]);
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long minNum = 0;
    long answer = long.MaxValue;
    int countMemo = 0;
    List<long> answerList = new List<long>();
    List<long> answerSubList = new List<long>();

    for(int i = 0; i < n; i++)//??????
    {
      minNum = nums[i];
      answerList.Clear();
      answerSubList.Clear();
      countMemo = 0;
      for(int j = 0; j < n; j++)
      {
        if(nums[j] >= minNum)
        {
          countMemo++;
          if(countMemo == k)
          {
            for(int l = 0; l < k; l++)
            {
              answerSubList.Add(nums[j-l]);
            }
          }else if(countMemo > k) answerSubList.Add(nums[j]);
        }else
        {
          if(countMemo >= k)
          {
            answerSubList.Sort((a, b) => a.CompareTo(b));
            for(int l = 0; l < answerSubList.Count()-k+1; l++)
            {
              answerList.Add(answerSubList[l]);
            }
          }
          answerSubList.Clear();
          countMemo = 0;
        }
      }
      if(countMemo >= k)
      {
        answerSubList.Sort((a, b) => a.CompareTo(b));
        for(int l = 0; l < answerSubList.Count()-k+1; l++)
        {
          answerList.Add(answerSubList[l]);
        }
      }
      if(answerList.Count() < q) continue;
      else
      {
        answerList.Sort((a, b) => a.CompareTo(b));
        answer = Math.Min(answer, answerList[q-1]-minNum);
      }
    }
    
		Console.WriteLine(answer);
	}
}