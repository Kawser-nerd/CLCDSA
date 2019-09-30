using System;
class Program
{
	static void Main()
	{
  int answer = 0;
  string[] input = Console.ReadLine().Split(' ');//Split???????????????????
  int h = int.Parse(input[0]);//????
  int w = int.Parse(input[1]);//????
  int[,] moveMatrix = new int [10,10];//??
  
    for(int i = 0; i < 10; i++)//??????
    {
	     int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
	     for(int j = 0; j < 10; j++) moveMatrix[i,j] = nums[j];//???????
    }

    int[] walls = new int[10];//?????
    
      for(int i = 0; i < h; i++)//??????
      {
  	     int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
  	     for(int j = 0; j < w; j++) 
         {
          if(nums[j] != -1)  walls[nums[j]]++;//???????
         }
      }

    for(int k = 0; k < 10; k++)
    {
      for(int i = 0; i < 10; i++)
      {
        for(int j = 0; j < 10; j++)
        {
          if(moveMatrix[i,j] > moveMatrix[i,k] + moveMatrix[k,j])
            moveMatrix[i,j] = moveMatrix[i,k] + moveMatrix[k,j];//?????
        }
      }
    }

    for(int i = 0; i < 10; i++)
    {
    answer += moveMatrix[i,1] * walls[i];
    }

	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}