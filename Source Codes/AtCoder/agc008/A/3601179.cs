using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long x = long.Parse(input[0]);
		long y = long.Parse(input[1]);
    long answer = Math.Abs(Math.Abs(x)-Math.Abs(y));

    if(x<y && y<=0 || 0<=x && x<y) answer += 0;
    else if(y<x && x<0 || 0<y && y<x) answer += 2;
    else answer += 1;

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}