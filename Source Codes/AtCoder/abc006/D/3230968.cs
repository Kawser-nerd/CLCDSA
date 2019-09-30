using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
  static List<int> lastNum = new List<int>();//????

	static void Main()
	{
	int n = int.Parse(Console.ReadLine());
  int[] nums = new int[n];

    for(int i = 0; i < n; i++)
    {
    nums[i] = int.Parse(Console.ReadLine());
    }
    
    lastNum.Add(nums[0]);
    for(int i = 1; i < n; i++)
    {
      if(nums[i] > lastNum[lastNum.Count()-1]) lastNum.Add(nums[i]);//??????????
      else lastNum[FindNum(nums[i])] = nums[i];
    }
  
	Console.WriteLine(n-lastNum.Count());
	}

  static int FindNum(int num)//??num????????
  {
  if(num<lastNum[0]) return 0;
  
    for(int i = 0; i < lastNum.Count(); i++)//?????????????????????
    {
    int min = 0;
    int max = lastNum.Count() - 1;

      while (true)
      {
      int mid = min + (max - min) / 2;
      if(lastNum[mid] < num) min = mid;
      else max = mid;

        if(max - min <= 1)
        {
        if(num < lastNum[min]) return min;
        else return max;
        }
    
      }
    }
    return -1;
  }
  
}