using System;

class Program
{
	static void Main()
	{
		int N = int.Parse(Console.ReadLine());
		int NG1 = int.Parse(Console.ReadLine());
		int NG2 = int.Parse(Console.ReadLine());
		int NG3 = int.Parse(Console.ReadLine());

		if(N == NG1 || N == NG2 || N == NG3)
		{
			Console.WriteLine("NO");
			return;
		}

		for(int i = 0; i < 100;i++)
		{
			int tmp = N;
			for(int j = 3; j > 0; j--)
			{
				if(N - j <= 0)
				{
					Console.WriteLine("YES");
					return;
				}
				if(N - j != NG1 && N - j != NG2 && N - j != NG3)
				{
					N -= j;
					break;
				}
			}
			if(N == tmp) break;
		}
		Console.WriteLine("NO");
	}
}