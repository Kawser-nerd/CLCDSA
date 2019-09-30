using System;

class TooManyTabls
{
	static public void Main(string[] args)
	{
		int N, L;
		string[] vals = Console.ReadLine().Split(' ');
		N = int.Parse(vals[0]);
		L = int.Parse(vals[1]);
		string S = Console.ReadLine();

		int numofTabs = 1;
		int numofCrashes = 0;
		for(int i=0; i < N; i++)
		{
			if(S[i] == '+')
			{
				if(++numofTabs > L)
				{
					numofTabs = 1;
					numofCrashes++;
				}
			}
			else
			{
				numofTabs--;
			}
		}
		Console.WriteLine(numofCrashes);
	}
}