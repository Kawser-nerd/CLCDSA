using System;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	int h = int.Parse(input[0]);
	int w = int.Parse(input[1]);
  int[,] matrix = new int [h,w];//??
  
  for(int i = 0; i < h; i++)
    {
      int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
      for(int j = 0; j < w; j++)matrix[i,j] = nums[j];
    }

  int moveTime = 0;

  int pickUp = 0;//???????

  for(int i = 0; i < h; i++)//????????
    {
    if(i % 2 == 0)//?????
      {
      for(int j = 0; j < w; j++)//????????
        {
        if(matrix[i,j] % 2 == 1)
          {
          if(pickUp == 1)pickUp = 0;
          else pickUp = 1;
          }
        if(pickUp == 1)
          {
          if(j+1 < w) moveTime++;
          else if(i+1 < h) moveTime++;
          }

        }

      }

      if(i % 2 == 1)//?????
        {
        for(int j = w-1; j >= 0; j--)//????????
          {
          if(matrix[i,j] % 2 == 1)
            {
            if(pickUp == 1)pickUp = 0;
            else pickUp = 1;
            }
          if(pickUp == 1)
            {
            if(j-1 >= 0) moveTime++;
            else if(i+1 < h) moveTime++;
            }

          }

        }

	  }

    Console.WriteLine(moveTime);
    pickUp = 0;

    for(int i = 0; i < h; i++)//??????????
      {
      if(i % 2 == 0)//?????
        {
        for(int j = 0; j < w; j++)//????????
          {
          if(matrix[i,j] % 2 == 1)
            {
            if(pickUp == 1)pickUp = 0;
            else pickUp = 1;
            }
          if(pickUp == 1)
            {
            if(j+1 < w) Console.WriteLine(((int)i+1) + " " + ((int)j+1) + " " + ((int)i+1) + " " + ((int)j+2));
            else if(i+1 < h) Console.WriteLine(((int)i+1) + " " + ((int)j+1) + " " + ((int)i+2) + " " + ((int)j+1));
            }

          }

        }

        if(i % 2 == 1)//?????
          {
          for(int j = w-1; j >= 0; j--)//????????
            {
            if(matrix[i,j] % 2 == 1)
              {
              if(pickUp == 1)pickUp = 0;
              else pickUp = 1;
              }
            if(pickUp == 1)
              {
              if(j-1 >= 0) Console.WriteLine(((int)i+1) + " " + ((int)j+1) + " " + ((int)i+1) + " " + j);
              else if(i+1 < h) Console.WriteLine(((int)i+1) + " " + ((int)j+1) + " " + ((int)i+2) + " " + ((int)j+1));
              }

            }

          }

  	  }
    
  }
}