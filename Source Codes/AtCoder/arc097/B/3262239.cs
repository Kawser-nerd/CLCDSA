using System;
class Program
{

static string[] input = Console.ReadLine().Split(' ');
static int n = int.Parse(input[0]);
static int m = int.Parse(input[1]);
static int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
static int[] parents = new int[n];//?
  
	static void Main()
	{
    int answer = 0;
    
    for(int i = 1; i < n; i++)
    {
    parents[i] = i;
    }
  
    for(int i = 0; i < m; i++)
    {
      int[] edges = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
      
        if(whatParent(edges[0]-1) != whatParent(edges[1]-1))
          parents[whatParent(edges[0]-1)] = whatParent(edges[1]-1);//???????????2??????????
      
    }

    for(int i = 0; i < n; i++)
    {
      if(whatParent(nums[i]-1) == whatParent(nums[nums[i]-1]-1)) answer++;
    }

    Console.WriteLine(answer);
    
	}

  static int whatParent(int child)
  {
    if(parents[child] == child) return child;
    else return parents[child] = whatParent(parents[child]);
  }
  
}