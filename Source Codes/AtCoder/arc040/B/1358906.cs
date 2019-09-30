using System;
using System.Text;

class ABC040B
{
	static public void Main(string[] args)
	{
		int N, R;
		string[] vals = Console.ReadLine().Split(' ');
		N = int.Parse(vals[0]);
		R = int.Parse(vals[1]);
		StringBuilder S = new StringBuilder(Console.ReadLine());

		bool allPainted = true;
		int lastTarget = 0;
		for(int k=0; k < N; k++)
		{
			if(S[k] == '.')
			{
				allPainted = false;
				lastTarget = k;
			}
		}
		if(allPainted)
		{
			Console.WriteLine(0);
			return;
		}

		int i = 0;
		int time = 0;
		while(true)
		{
			time++;
			if(i+R-1 >= lastTarget)
			{
				break;
			}
			else if(S[i] == '.')
			{
				for(int j=i; j <= i+R-1; j++)
				{
					S[j] = 'o';
				}
			}
			else
			{
				i++;
			}
		}

		Console.WriteLine(time);
	}
}