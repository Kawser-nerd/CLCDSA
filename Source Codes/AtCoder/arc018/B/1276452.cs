using System;

class ARC018B
{
	static public void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		int[,] p = new int[N,2];

		for(int i=0; i<N; i++)
		{
			string[] vals = Console.ReadLine().Split(' ');
			p[i,0] = int.Parse(vals[0]);
			p[i,1] = int.Parse(vals[1]);
		}

		int count = 0;
		for(int i=0; i<N-2; i++)
		{
			for(int j=i+1; j<N-1; j++)
			{
				for(int k=j+1; k<N; k++)
				{
					long x1 = p[j,0] - p[i,0];
					long y1 = p[j,1] - p[i,1];
					long x2 = p[k,0] - p[i,0];
					long y2 = p[k,1] - p[i,1];
					long cz = x1 * y2 - y1 * x2;
					if(cz != 0 && cz % 2 == 0)
						count++;
				}
			}
		}
		Console.WriteLine(count);
	}
}