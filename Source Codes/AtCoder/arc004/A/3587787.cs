using System;
using System.Collections;
using System.Linq;


public class Test
{
	public static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		
		double[] numx = new double[n];
		double[] numy = new double[n];

		double x = 0;
		double y = 0;
		double ans = 0;
		double max = 0;
		string[] line;
		for(int i = 0 ; i < n ; i++)
		{
			line = Console.ReadLine().Split(' ');
			numx[i] = double.Parse(line[0]);
			numy[i] = double.Parse(line[1]);
		}

		for(int i = 0 ; i < n-1 ; i++)
		{
			for(int j = i+1 ; j < n ; j++)
			{
				x = Math.Abs(numx[i]-numx[j]);
				y = Math.Abs(numy[i]-numy[j]);
				ans = Math.Sqrt((Math.Pow(x,2)+(Math.Pow(y,2))));
				if(ans > max)
				{
					max = ans;
				}
			}
		}
		Console.WriteLine(max.ToString("F6"));
	}
}