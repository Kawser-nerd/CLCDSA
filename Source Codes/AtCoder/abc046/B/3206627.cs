using System;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	int n = int.Parse(input[0]);
	int k = int.Parse(input[1]);
    long answer = k;
    for(int i = 2; i <= n; i++)answer *= k - 1;

	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}