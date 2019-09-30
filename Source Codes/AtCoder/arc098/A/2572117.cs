using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		int n;
		string s;
		n = int.Parse(Console.ReadLine());
		s = Console.ReadLine();
		int[] count = new int[n];
		int count2 = 0;
		for(int i=0;i<n;i++)
		{
			if(0<=i-1&&s[i-1]=='W')count2++;
			count[i] = count2;
		}
		count2 = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(n>i+1&&s[i+1]=='E')count2++;
			count[i] += count2;
		}
		Console.WriteLine(count.Min());
	}
}