using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static int n = int.Parse(Console.ReadLine());
static int[] nums = new int[n-1];
static List<int>[] childrenList = new List<int>[n+1];
static List<int>[] answerList = new List<int>[n+1];
static int[] answers = new int[n+1];

	static void Main()
	{
    for(int i = 0; i <= n; i++)
    {
      answers[i] = -1;
      childrenList[i] = new List<int>();
      answerList[i] = new List<int>();
    }
  
		for(int i = 0; i < n-1; i++)
    {
      nums[i] = int.Parse(Console.ReadLine());
      childrenList[nums[i]].Add(i+2);
    }
    
		Console.WriteLine(DP(1));
	}

  static int DP(int num)
  {
    if(answers[num] != -1) return answers[num];
    int answer = 0;

    for(int i = 0; i < childrenList[num].Count(); i++)
    {
      answerList[num].Add(DP(childrenList[num][i]));
    }
    answerList[num].Sort((a, b) => b.CompareTo(a));//??????
    
    for(int i = 0; i < childrenList[num].Count(); i++)
    {
      answer = Math.Max(answer, i+1+answerList[num][i]);
    }

    return answers[num] = answer;
  }
}