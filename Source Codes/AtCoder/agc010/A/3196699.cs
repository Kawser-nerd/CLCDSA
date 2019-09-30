using System;
class Program
{
	static void Main()
	{
	int n = int.Parse(Console.ReadLine());//int.Parse???????????
	int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
	//??
    int a = 0;
   	  for(int i = 0; i<n;i++)
      {
       if(nums[i]%2==1)a++; 
      }
	Console.WriteLine((a % 2 == 0) ? "YES" : "NO");
	}
}