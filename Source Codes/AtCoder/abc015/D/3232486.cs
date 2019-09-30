using System;
class Program
{
	static void Main()
	{
  int answer = 0;
	int w = int.Parse(Console.ReadLine());
  string[] input = Console.ReadLine().Split(' ');
	int n = int.Parse(input[0]);
	int k = int.Parse(input[1]);
  int[,] vertexes = new int[n,2];//???????
    for(int i = 0; i < n; i++)
    {
    int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);//?????????
    vertexes[i,0] = nums[0];
    vertexes[i,1] = nums[1];
    }
    int[,,] answers = new int[n+1,w+1,k+1];

    
    for(int y = 0; y <= w; y++)
    {
      for(int z = 0; z <= k; z++)
      {
        for(int x = 0; x < n; x++)
        {
          if(y-vertexes[x,0] >= 0 && z-1 >= 0)
            answers[x+1,y,z] = Math.Max(answers[x, y, z], 
              answers[x, y - vertexes[x,0], z-1] + vertexes[x, 1]);
          else answers[x+1,y,z] = answers[x,y,z];          
        }
      }
    }
  
	Console.WriteLine(answers[n,w,k]);
	}
}