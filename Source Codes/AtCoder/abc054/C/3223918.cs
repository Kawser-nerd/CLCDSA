using System;
using System.Linq;
using System.Collections.Generic;
class Program
{

static string[] input = Console.ReadLine().Split(' ');//Split???????????????????
static int n = int.Parse(input[0]);//???
static int m = int.Parse(input[1]);//??
static int[,] path = new int[n,n];//????
static int answer = 0;

	static void Main()
	{
    for(int i = 0; i < m; i++)//???????
    {
    int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
    path[nums[0]-1, nums[1]-1]++;
    path[nums[1]-1, nums[0]-1]++;
    }

    List<int> numListOriginal = Enumerable.Range(1,n-1).ToList();//??
    List<int> numListFinal = new List<int>(){0};
    Permutation(numListOriginal, numListFinal);//?????
    
	Console.WriteLine(answer);
	}

  static void Permutation(List<int> numListOriginal, List<int> numListFinal)//?????
  {
    for(int i = 0; i < numListOriginal.Count(); i++)
    {
      int x = numListOriginal[i];//??????
      numListFinal.Add(x);
      numListOriginal.RemoveAt(i);
      
      if(numListOriginal.Count() > 0) Permutation(numListOriginal, numListFinal);
      else CheckPath(numListFinal);
      
      numListOriginal.Insert(i, x);//listOriginal???
      numListFinal.RemoveAt(numListFinal.Count()-1);
    }
  }

  static void CheckPath(List<int> numListFinal)
  {
    for(int i = 0; i < numListFinal.Count()-1; i++)
    {
      if(path[numListFinal[i],numListFinal[i+1]] == 0) break;//???????????
      if(i == numListFinal.Count()-2) answer++;
    }
  
  }
  
}