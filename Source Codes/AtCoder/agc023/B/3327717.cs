using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());//int.Parse???????????
    string[] nums = new string[2*n];
    bool check = true;
    int answer = 0;
		for(int i = 0; i < n; i++)
    {
      nums[i] = Console.ReadLine();
      nums[n+i] = nums[i];
    }

    for(int i = 0; i < n; i++)
    {
      check = true;
      for(int j = 0; j < n-1; j++)
      {
        for(int k = j+1; k < n; k++)
        {
          if(nums[j+i][k] != nums[k+i][j]) check = false;
        }
      }
      if(check) answer += n;
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}