using System;
 
public class Test
{
	public static void Main()
	{
		// your code goes here
		int count = 0, n = int.Parse(Console.ReadLine());
		int[,] red = new int[n,2];
		int[,] blue = new int[n,2];
		bool[] check = new bool[n];
		red = Read(n);
		blue = Read(n);
		red = Sort(n, red);
		blue = Sort(n, blue);
		
		for(int i=0;i<n;i++)
		{
			int a=0, b=0, j;
			bool c = false;
			for(j=0;j<n;j++)
			{
				if(check[j]==false&&red[j,0]>blue[i,0])
				{
					break;
				}
			}
			//Console.WriteLine(blue[i,1]);
			for(j=j-1;j>=0;j--)
			{
				if(check[j]==false&&red[j,1]<blue[i,1]&&a<=red[j,1])
				{
					//Console.WriteLine(red[j,1]);
					a = red[j,1];
					b = j;
					c = true;
				}
			}
			if(c)
			{
				count++;
				check[b]=true;
			}
			//Console.WriteLine();
		}
		Console.WriteLine(count);
	}
	public static int[,] Read(int n)
	{
		int[,] point = new int[n,2];
		for(int i=0;i<n;i++)
		{
			string[] line = Console.ReadLine().Split(' ');
			point[i,0] = int.Parse(line[0]);
			point[i,1] = int.Parse(line[1]);
		}
		return point;
	}
	public static int[,] Sort(int n, int[,] point)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(point[i,0]>point[j,0])
				{
					int a = point[i,0], b = point[i,1];
					point[i,0] = point[j,0];
					point[i,1] = point[j,1];
					point[j,0] = a;
					point[j,1] = b;
				}
			}
		}
		return point;
	}
}