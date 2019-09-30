using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long m = long.Parse(input[1]);
		long answer = 0;

    if(n >= 2 && m >= 2) answer = (n-2)*(m-2);
    else if(n == 1 && m >= 2) answer = m-2;
    else if(n >= 2 && m == 1) answer = n-2;
    else if(n == 1 && m == 1) answer = 1;

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}