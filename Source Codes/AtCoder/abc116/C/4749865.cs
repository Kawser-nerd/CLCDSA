using System;


public class C
{
	public static void Main()
	{
		int N = Int32.Parse(Console.ReadLine());
		int[] r = new int[N + 2];
		r[N + 1] = 0;  // sentinel
		
		string[] args = Console.ReadLine().Split(' ');

		int hMax = 0;
		for(int i = 0; i < N; i++)
		{
			int h = Int32.Parse(args[i]);
			if(h > hMax)
				hMax = h;
			r[i + 1] = h;	
		}
		
		int counter = 0;
		for(int i = 1; i <= hMax; i++)
		{
			for(int j = 1; j <= N; j++)
			{	
				if(r[j] > 0)
				{
					counter++;
					do
					{
						r[j]--;
						j++;
					}
					while(r[j] > 0);
				}
			}			
		}
		
		Console.WriteLine(counter);
	}
}