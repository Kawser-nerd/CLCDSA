using System;


public class B
{	
	public static void Main()
	{	
		int N = Int32.Parse(Console.ReadLine());
		string[] args = Console.ReadLine().Split(' ');
		
		int LMax = 0;
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			int L = Int32.Parse(args[i]);
			sum += L;
			LMax = Math.Max(L, LMax);
		}
		
		Console.WriteLine((LMax < (sum - LMax)) ? "Yes" : "No");
	}
}