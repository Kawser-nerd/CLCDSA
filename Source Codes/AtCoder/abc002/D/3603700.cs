using System;
using System.Collections;
using System.Linq;


public class Test
{	
	public static int max = 0;
	public static int n = 0;
	public static void Main()
	{
		string[] str = Console.ReadLine().Split(' ');
		n = int.Parse(str[0]);
		int m = int.Parse(str[1]);
		bool[,] C = new bool[n,n];
		string F = "";
	
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ;j++)
			{
				if(i==j) C[i,j] = true;
			}
		}

		for(int i = 0 ; i < m ; i++)
		{
			str = Console.ReadLine().Split(' ');
			int x = int.Parse(str[0]) -1;
			int y = int.Parse(str[1]) -1;
			C[x,y] = true;
			C[y,x] = true;
		}

		DFS(C, F);
		Console.WriteLine(max);
	}

	public static void DFS (bool[,] C, string F)
	{
		if(F.Length == n)
		{
			Process(C, F);
		}
		else {
			DFS (C, F+"1");
			DFS (C, F+"0");
		}
	}

	public static void Process(bool[,] C , string F)
	{
        char[] c = F.ToCharArray();
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(c[i]=='1' && c[j]=='1')
				{
					if(!C[i,j]) return;
				}
			}
		}

		int sum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(c[i]== '1') sum++;
		}

		max = Math.Max(max, sum);
	}
}