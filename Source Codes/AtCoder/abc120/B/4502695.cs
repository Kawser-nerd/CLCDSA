using System;
using System.Collections.Generic;

class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split(' ');
		int A = int.Parse(str[0]);
		int B = int.Parse(str[1]);
		int K = int.Parse(str[2]);
		int cnt = 0;
		int ans;

		for (int i = 100;; i--)
		{
			if(A%i == 0 && B%i == 0)
			{
				cnt++;
				if(cnt == K)
				{
					ans = i;
					break;
				}	
			}
		}
		Console.WriteLine(ans);
	}
}