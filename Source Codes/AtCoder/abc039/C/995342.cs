using System;

class Piano
{
	static string kbColor = "WBWBWWBWBWBW";
	static string[] DoReMi = { "Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si" };

	static char GetColor(int i)
	{
		return kbColor[i % 12];
	}

	static public void Main(string[] args)
	{
		string S = Console.ReadLine();

		for(int i=0; i<12; i++)
		{
			for(int j=0; j<20; j++)
			{
				if(GetColor(i+j) != S[j])
				{
					goto nextLoop;
				}
			}
			Console.WriteLine(DoReMi[i]);
			return;
			nextLoop:
			;
		}
	}
}