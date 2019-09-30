using System;
class Program
{
	static void Main()
	{
	   int n = int.Parse(Console.ReadLine());//int.Parse???????????
     int[,] vertexes = new int[n,2];
     for(int i = 0; i < n; i++)
     {
     int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
     vertexes[i,0] = nums[0];
     vertexes[i,1] = nums[1];
     }
     double maxDistance = 0;

     for(int i = 0; i < n; i++)
     {
        for(int j = i+1; j < n; j++)
        {
        double x = vertexes[i,0] - vertexes[j,0];
        double y = vertexes[i,1] - vertexes[j,1];
        double distance = x*x + y*y;
        if(distance > maxDistance)maxDistance = distance;//???????
        }
     }

     maxDistance = System.Math.Sqrt(maxDistance);
     	
	   Console.WriteLine(maxDistance);
	}
}