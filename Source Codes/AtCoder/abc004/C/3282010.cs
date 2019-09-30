using System;
class Replacing
{
	static int[] cards = {1, 2, 3, 4, 5, 6};
	
	static void Main(string[] args)
	{
		int n = int.Parse(Console.ReadLine());
		n = n % 30;
		for (int i = 0; i < n; i++)
		{
			replace(i);
		}
		Console.WriteLine("" + cards[0] + cards[1] + cards[2] + cards[3] + cards[4] + cards[5]);
	}
	static void replace(int i)
	{
		int buf = cards[i % 5];
		cards[i % 5] = cards[i % 5 + 1];
		cards[i % 5 + 1] = buf;
	}
}