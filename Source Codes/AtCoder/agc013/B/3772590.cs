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
		int m = int.Parse(input[1]);
    bool[] usedVertexes = new bool[n];//???????
    List<int>[] nextList = new List<int>[n];//????????????????
    List<int> firstList = new List<int>();
    List<int> secondList = new List<int>();
    for(int i = 0; i < n; i++) nextList[i] = new List<int>();//??????
    
    for(int i = 0; i < m; i++)
    {
      int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
      if(i == 0)
      {
        firstList.Add(nums[0]-1);
        secondList.Add(nums[1]-1);
        usedVertexes[nums[0]-1] = true;
        usedVertexes[nums[1]-1] = true;
      }
      nextList[nums[0]-1].Add(nums[1]-1);//?????????
      nextList[nums[1]-1].Add(nums[0]-1);
    }

    while(true)
    {
      bool continueBool = false;
      for(int i = 0; i < nextList[firstList[firstList.Count()-1]].Count(); i++)
      {
        //Console.WriteLine(firstList[firstList.Count()-1]+"a"+nextList[firstList[firstList.Count()-1]][i]);
        if(!usedVertexes[nextList[firstList[firstList.Count()-1]][i]])
        {
          usedVertexes[nextList[firstList[firstList.Count()-1]][i]] = true;
          firstList.Add(nextList[firstList[firstList.Count()-1]][i]);
          continueBool = true;
          break;
        }
      }
      if(!continueBool) break;
    }

    while(true)
    {
      bool continueBool = false;
      for(int i = 0; i < nextList[secondList[secondList.Count()-1]].Count(); i++)
      {
        if(!usedVertexes[nextList[secondList[secondList.Count()-1]][i]])
        {
          usedVertexes[nextList[secondList[secondList.Count()-1]][i]] = true;
          secondList.Add(nextList[secondList[secondList.Count()-1]][i]);
          continueBool = true;
          break;
        }
      }
      if(!continueBool) break;
    }

    int[] answers = new int[firstList.Count() + secondList.Count()];
    for(int i = 0; i < firstList.Count(); i++)
    {
      answers[i] = firstList[firstList.Count()-1-i]+1;
    }
    for(int i = 0; i < secondList.Count(); i++)
    {
      answers[firstList.Count()+i] = secondList[i]+1;
    }

		Console.WriteLine(firstList.Count() + secondList.Count());
    Console.WriteLine(string.Join(" ", answers));
	}
}