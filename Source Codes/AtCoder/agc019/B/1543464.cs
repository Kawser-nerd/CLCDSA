using System;

class AGC019B
{
	static public void Main(string[] args)
	{
		string A = Console.ReadLine();
		long ans = 1;
		int[] count = new int[26];
		count[A[0]-'a']++;
		for(int i=1; i < A.Length; i++)
		{
			char c = A[i];
			int canReverse = 0;
			for(int j=0; j < 26; j++)
			{
				if(c-'a' != j)
				{
					canReverse+=count[j];
				}
			}
			ans += canReverse;
			count[c-'a']++;
		}
		Console.WriteLine(ans);
	}
}