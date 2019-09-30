using System;

class ColorfulSlimes
{
	static public void Main(string[] args)
	{
		int N, x;
		string[] vals = Console.ReadLine().Split(' ');

		N = int.Parse(vals[0]);
		x = int.Parse(vals[1]);
		vals = Console.ReadLine().Split(' ');
		int[] a = new int[N+1];
		for(int i=1; i<=N; i++)
			a[i] = int.Parse(vals[i-1]);

		int[,] b = new int[N+1,N];
		for(int i=1; i<=N; i++)
		{
			b[i,0] = a[i];
		}
		for(int i=1; i<=N; i++)
		{
			for(int k=1; k<=N-1; k++)
			{
				int j;
				if(i - k >= 1)
					j = i - k;
				else
					j = i - k + N;
				b[i,k] = Math.Min(b[i,k-1], a[j]); 
			}
		}

		long minTime = long.MaxValue;
		for(int k = 0; k <= N-1; k++)
		{
			long t = 0;
			for(int i=1; i <= N; i++)
			{
				t += b[i,k];
			}
			t += (long)k * x;
			if(t < minTime)
			{
				minTime = t;
			}
		}
		Console.WriteLine(minTime);	
	}

}